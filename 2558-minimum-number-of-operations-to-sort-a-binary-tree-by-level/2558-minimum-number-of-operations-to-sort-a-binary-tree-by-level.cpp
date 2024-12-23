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
/*
✅ Key Observations
Level-wise Traversal: We need to perform a level-order traversal (BFS) to process nodes level-by-level.
Sorting by Swapping: At each level, the problem reduces to finding the minimum number of swaps to sort an array of values.
*/
    int countMinSwaps(vector<int>& orgVec)
    {
        vector<int>sortedVec(orgVec.begin() , orgVec.end());
        sort(sortedVec.begin() , sortedVec.end());
        int swaps=0;
        unordered_map<int,int> mp;

        int n=orgVec.size();
        for(int i=0;i<n;i++)
        {
            mp[orgVec[i]] = i;

        }


        for(int i=0;i<n;i++)
        {
            if(orgVec[i] == sortedVec[i])
                continue; //dono element same jgh p h to skip
        //else
        //orgVec ka element ka index nikalo;
            int orgElementIdx = mp[sortedVec[i]];
         
           //update the index of that elemet
           mp[orgVec[i]] = orgElementIdx;

   //sortedVec ka element jo ki iss index{orgElementIdx} p hoga , wo shi  position hoga
         swap ( orgVec[i] ,  orgVec[orgElementIdx] ); //
           swaps++;
        }
return swaps;
    }



    int minimumOperations(TreeNode* root) {
        //bfs
        int minSwaps=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
             vector<int>vec;
            while(n--)
            {
            auto fnode = q.front();
            q.pop();
           
            vec.push_back(fnode->val);
            if(fnode->left)
                q.push(fnode->left);
            if(fnode->right)
                q.push(fnode->right);

            }
            //ek level khtm
            minSwaps += countMinSwaps(vec);

           
            
        }

return minSwaps;

    }
};