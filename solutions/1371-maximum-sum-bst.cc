#include <algorithm>
#include <climits>
#include <tuple>
using namespace std;

// 1373 - Maximum Sum BST in Binary Tree
// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Time: O(n) | Space: O(h)

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        return get<4>(aux(root));
    }

private:
    // {isBST, sum, minValue, maxValue, bestSum}
    using Result = tuple<bool, int, int, int, int>;

    Result aux(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN, 0};
        }

        // Recursive case
        auto [leftBST, leftSum, leftMin, leftMax, leftBest] =
        aux(root->left);

        auto [rightBST, rightSum, rightMin, rightMax, rightBest] =
        aux(root->right);

        int bestSum = max(leftBest, rightBest);

        if (leftBST && rightBST && (leftMax < root->val && root->val < rightMin)) {
            int sum = leftSum + rightSum + root->val;
            int minValue = min(leftMin, root->val);
            int maxValue = max(rightMax, root->val);

            bestSum = max(bestSum, sum);

            return {true, sum, minValue, maxValue, bestSum};
        }

        return {false, 0, 0, 0, bestSum};
    }
};
