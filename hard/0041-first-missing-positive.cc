// 0041 - First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
// Time: O(n) | Space: O(1)
//
// In-place cyclic placement: each value x in [1, n] is moved to
// index x - 1. The first index containing an incorrect value
// determines the smallest missing positive integer.

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n &&
                nums[i] != nums[nums[i] - 1]) {

                int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
                }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
