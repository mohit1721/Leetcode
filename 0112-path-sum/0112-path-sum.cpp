/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int currSum, int targetSum) {
        if (!root)
            return false;
        // agar leaf tk phunch gye
        currSum+=root->val;

        if (!root->left && !root->right) {
            return (currSum == targetSum);
        }

        bool left = solve(root->left, currSum , targetSum);
        bool right = solve(root->right, currSum  , targetSum);

        currSum-=root->val; //backTrack

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        return solve(root, 0, targetSum);
    }
};