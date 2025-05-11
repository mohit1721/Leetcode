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
    void solve(TreeNode* root, string &curr, int &ans){
        if(!root) return;
        curr+= to_string(root->val);

        if(!root->left && !root->right){
            ans+=stoi(curr);
        }
        
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
        curr.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        string curr="";
        int ans=0;
        solve(root, curr, ans);
        return ans;
    }



};