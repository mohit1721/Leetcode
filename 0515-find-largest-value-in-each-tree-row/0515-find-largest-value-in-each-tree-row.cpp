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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;

if(!root) return {};

        q.push(root);
      

        while(!q.empty()){
            //  std::priority_queue<int>maxHeap;
            // #2. 
            int maxElement=INT_MIN;
            int n=q.size();
            while(n--)
            {
                auto fnode = q.front();
                q.pop();
                // maxHeap.push(fnode->val);
                maxElement = max(maxElement, fnode->val);
                if(fnode->left)
                {
                    q.push(fnode->left);
                }
                if(fnode->right)

                {
                    q.push(fnode->right);
                }
            }
            //ab ek ka maximum find

            // int maxNode=maxHeap.top();
            // maxHeap.pop();

            ans.push_back(maxElement);
       

        }

return ans;


    }
};