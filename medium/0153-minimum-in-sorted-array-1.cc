// 0153 - Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Time: O(log n) | Space: O(log n)

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinRec(nums, 0, nums.size() - 1);
    }

private:
    int findMinRec(const vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];

        int m = l + (r - l) / 2;

        if (nums[m] < nums[r])
            return findMinRec(nums, l, m);
        else
            return findMinRec(nums, m + 1, r);
    }
};
