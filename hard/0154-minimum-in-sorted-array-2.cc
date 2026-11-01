// 0154 - Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Time: O(n) | Space: O(1)
//
// Although binary search is typically O(log n), duplicates can make it
// impossible to determine which half contains the minimum. In the worst
// case, binary search must discard elements one by one, taking O(n) time.
//
// This implementation uses a simple linear scan, achieving the same
// worst-case time complexity with constant auxiliary space.

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];

        for (const int& x : nums) {
            if (x < min) min = x;
        }

        return min;
    }
};
