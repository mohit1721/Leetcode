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
    int leftLeaveSum(TreeNode* root , TreeNode* parent){
        if(!root) return 0;
        //ek casse
        //if leave
        if(!root->left && !root->right){
            // aur, ye apne parent ka left child hoga
            if(parent && parent->left == root){
                return root->val;
            }
        }
        // left/right

        int ls = leftLeaveSum(root->left , root);//root/ currentNode will be parent
        int rs = leftLeaveSum(root->right, root);// same....

        return ls + rs ;

    }
// #2. method 2 , using flag
    int solve(TreeNode* root, bool isLeftChild){
        if(!root) return 0;

        //
        if(!root->left && !root->right){
            if(isLeftChild){
                return root->val;
            }
        }

        int ls = solve(root->left, true);
        int rs = solve(root->right, false);

        return ls+rs;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        // return leftLeaveSum(root , NULL);
        return solve(root, false);

    }
};