// 0033 - Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time: O(log n) | Space: O(log n)

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchAux(nums, 0, nums.size() - 1, target);
    }

private:
    int searchAux(const vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;

        int m = left + (right - left) / 2;

        if (nums[m] == target) return m;

        if (nums[left] <= nums[m]) {
            if (nums[left] <= target && target < nums[m])
                return searchAux(nums, left, m - 1, target);
            else
                return searchAux(nums, m + 1, right, target);
        }
        else {
            if (nums[m] < target && target <= nums[right])
                return searchAux(nums, m + 1, right, target);
            else
                return searchAux(nums, left, m - 1, target);
        }
    }
};
