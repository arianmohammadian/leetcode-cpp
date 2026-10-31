#include <vector>
#include <queue>
using namespace std;

// 0207 - Course Schedule
// https://leetcode.com/problems/course-schedule/
// Time: O(V + E) | Space: O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const vector<int>& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int completed = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ++completed;

            for (int next : adj[course]) {
                --indegree[next];

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};