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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* node, int &maxSum) {
        if (!node) return 0;

        // Left & Right se max 0 ya valid value lo
        int leftGain = max(0, dfs(node->left, maxSum));
        int rightGain = max(0, dfs(node->right, maxSum));

        // Current node ko root maan ke max path
        int currentMax = node->val + leftGain + rightGain;

        // Global max update
        maxSum = max(maxSum, currentMax);

        // Parent ko return value — root se ek side path
        return node->val + max(leftGain, rightGain);
    }
};