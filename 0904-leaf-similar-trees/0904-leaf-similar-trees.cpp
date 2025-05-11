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
void preorder(TreeNode* root, string& s){
    if(!root) return;
    //leaf
    if(!root->left && !root->right){
        s+= to_string(root->val) + "-";
        return;
    }
    preorder(root->left, s);
    preorder(root->right, s);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a="";
        string b="";
        preorder(root1, a);
        preorder(root2, b);
        return a==b;
    }
};