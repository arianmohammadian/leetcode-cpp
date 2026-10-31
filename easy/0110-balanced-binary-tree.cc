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

// 0110 - Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// Time: O(n) average | Space: O(h)

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedAux(root).first;
    }

private:
    pair<bool, int> isBalancedAux(TreeNode* root) {
        // base case
        if(root == nullptr) return {true, 0};

        // recursive case
        pair<bool, int> left = isBalancedAux(root->left);
        pair<bool, int> right = isBalancedAux(root -> right);

        return {
            left.first && right.first && (abs(left.second - right.second) <= 1),
            1 + max(left.second, right.second)
        };
    }
};
