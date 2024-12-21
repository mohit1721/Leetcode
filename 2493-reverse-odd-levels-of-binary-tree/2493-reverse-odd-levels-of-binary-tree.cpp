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
    void solve(TreeNode*l , TreeNode* r, int level)
    {
        if(!l || !r) return ;

        //jisme sirf root h, level-0.. usko to reverse krna nhi h*

        //level 1 , jo level 0 k baad h, jisme sirf 2 nodes h , usko reverse
        if(level % 2 ==1)
        {
            int temp = l->val;
            l->val= r->val;
            r->val = temp;
        }

        //baaki rec.

        solve(l->left, r->right , level+1);
        solve(l->right , r->left , level +1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
    //using dfs
    solve(root->left, root->right, 1);
    return root;

    }
};