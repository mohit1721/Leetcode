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
    void solve(TreeNode* root, int target ,int& cnt, vector<int>&temp){
        if(!root) return;
        temp.push_back(root->val);

        solve(root->left, target ,cnt, temp);
        solve(root->right, target,cnt, temp);

        long long sum=0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            sum+=temp[i];
            if(sum==target) cnt++;
        }
        temp.pop_back();

    }


    int pathSum(TreeNode* root, int targetSum) {
        // if(!root) return 0;
        vector<int>temp;
        int cnt=0;
       solve(root, targetSum ,cnt, temp);
       return cnt;
    }
};