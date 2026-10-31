/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 0654 - Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
// Time: O(n^2) | Space: O(n^2)

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty()) return nullptr;

		int maxit = 0;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[maxit]) {
				maxit = i;
			}
		}

		vector<int> prefix(nums.begin(), nums.begin() + maxit);
		vector<int> suffix(nums.begin() + maxit + 1, nums.end());

		TreeNode* left = constructMaximumBinaryTree(prefix);
		TreeNode* right = constructMaximumBinaryTree(suffix);

		return new TreeNode(nums[maxit], left, right);
	}
};
