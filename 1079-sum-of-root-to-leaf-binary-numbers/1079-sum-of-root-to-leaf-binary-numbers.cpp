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
    void solve(TreeNode*root, string& curr, int &ans){
        if(!root) return;

        curr+= to_string(root->val);
        //if leaf
        if(!root->left && !root->right){
            ans+= stoi(curr, 0 , 2);
             
        }

        solve(root->left, curr , ans);
        solve(root->right, curr, ans);

        curr.pop_back(); //backtrack

    }

    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        string curr;
        solve(root , curr , ans);
        return ans;
    }



};