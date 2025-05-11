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
 void solve(TreeNode* root, string currString, int &ans){

         //jb leaf tk phuchenge tbhi kuchh krenge
         if(!root->left && !root->right)
         {
            //
            currString+=to_string(root->val);
            //
            ans+=stoi(currString); //0->starting index, 2->base
            
            return ;
         }
         //else l r
         string curr= to_string(root->val);
        
         if(root->left)
         solve(root->left , currString + curr, ans);
         if(root->right)
         solve(root->right , currString + curr, ans);
         

    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        string currString="";
      solve(root,currString,ans);

   return ans;




    }
};