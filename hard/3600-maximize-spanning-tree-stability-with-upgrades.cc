#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>

using namespace std;

// 3600 - Maximize Spanning Tree Stability with Upgrades
// https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
// Time: O(E log E + E * alpha(V)) | Space: O(V + E)

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);

        int counter = 0;
        priority_queue<int, vector<int>, greater<int>> weights;
        vector<int> upgraded;

        for (const auto& v : edges) {
            if (v[3] == 1) {
                if (!dsu.unite(v[0], v[1]))
                    return -1;

                upgraded.push_back(v[2]);
                counter++;
            }
        }

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] > b[2];
             });

        for (const auto& edge : edges) {
            if (edge[3] == 0 && dsu.unite(edge[0], edge[1])) {
                weights.push(edge[2]);
                counter++;
            }
        }

        if (counter != n - 1) return -1;

        int l = 0;
        while (l < k && !weights.empty()) {
            int w = weights.top();
            weights.pop();
            upgraded.push_back(2 * w);
            l++;
        }

        int minWeight = INT_MAX;

        if (!weights.empty())
            minWeight = weights.top();

        for (int w : upgraded)
            minWeight = min(minWeight, w);

        return minWeight;
    }
};
