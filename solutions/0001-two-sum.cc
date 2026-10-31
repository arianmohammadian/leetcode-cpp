#include <vector>
#include <unordered_map>

using namespace std;

// 0001 - Two Sum
// https://leetcode.com/problems/two-sum/
// Time: O(n) average | Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            auto it = m.find(target - nums[i]);

            if (it != m.end())
                return {it->second, i};

            m[nums[i]] = i;
        }

        return {};
    }
};
