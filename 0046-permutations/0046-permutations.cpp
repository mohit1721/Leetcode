class Solution {
public:
int n;
    void solve(vector<int>&nums, unordered_set<int>&st,vector<vector<int>>&ans,vector<int>&temp, int idx )
    {
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        //start from 0 & go till end
        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i])==st.end())
            {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                //go 
                solve(nums,st, ans,temp,idx+1);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        unordered_set<int>st;
        vector<int>temp;
        solve(nums,st,ans,temp , 0);

        return ans;

    }
};