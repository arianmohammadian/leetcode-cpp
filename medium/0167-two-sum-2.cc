// 0167 - Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Time: O(n) | Space: O(1)
//
// Two-pointer approach on a sorted array.
// Move the right pointer to decrease the sum,
// or the left pointer to increase it.
//
// A solution is always guaranteed.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target) return {i + 1, j + 1};
            else if (sum > target) --j;
            else ++i;
        }

        return {i + 1, j + 1};
    }
};
