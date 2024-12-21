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
    TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    int level =0;
    while(!q.empty())
    {
        int n = q.size(); //size of that level [all node in that level]
        vector<TreeNode*>lvlNodes;
        while(n--)
        {
            auto fnode = q.front();
            q.pop();

            lvlNodes.push_back(fnode); //nodes store kr rhe

            //
            if(fnode->left)
                q.push(fnode->left);
            if(fnode->right)
                q.push(fnode->right);

        }
        //ek level k saare nodes dal gaye..
        // ab chk, agar level odd h

        if(level%2==1)
        {
            //reverse all nodes of that level..
            int i=0;
            int j=lvlNodes.size()-1;// n nhi hoga*
            while(i<j)
            {
                int tempVal = lvlNodes[i]->val ;// vector m node stored h**
                lvlNodes[i]->val = lvlNodes[j]->val;
                lvlNodes[j]->val = tempVal;
                i++;
                j--;
            }
        }
        //else level inc. 
        level++;


    }     
   


   return root;



    }
};