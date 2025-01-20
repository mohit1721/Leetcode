class Solution {
public:
int n;
void solve(vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans, int idx)
{
   ans.push_back(temp);
      

    for(int i=idx;i<n;i++)
    {
        if(i>idx && nums[i] == nums[i-1])
            continue;

    temp.push_back(nums[i]);
    solve(nums,temp,ans,i+1);
    temp.pop_back();
     
    }
  
   

}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
vector<vector<int>> ans;
vector<int>temp;
 // Sort the input array to easily handle duplicates
    sort(nums.begin(), nums.end());
solve(nums,temp,ans,0);
return ans;


    }
};