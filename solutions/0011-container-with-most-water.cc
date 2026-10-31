#include <vector>
#include <algorithm>

using namespace std;

// 0011 - Container With Most Water
// https://leetcode.com/problems/container-with-most-water/
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaFound = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int h1 = height[i], h2 = height[j];
            int area = (j - i) * min(h1, h2);

            if (area > maxAreaFound) maxAreaFound = area;

            if (h1 <= h2) i++;
            else j--;
        }

        return maxAreaFound;
    }
};
