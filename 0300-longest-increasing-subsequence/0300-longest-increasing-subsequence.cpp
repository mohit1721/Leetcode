class Solution {
public:
    int solveMem(vector<int>&nums, int n , int curr , int prev,  vector<vector<int>>&dp){
        if(curr>=n) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int include = 0;

        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1  + solveMem(nums, n, curr+1 , curr , dp);
        }
        int exclude = 0 + solveMem(nums, n, curr+1 , prev, dp);

        return dp[curr][prev+1] =  max(include, exclude);
    }
    int lisTab(vector<int>& nums){
              int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    for(int curr=n-1;curr>=0;curr--){
        for(int prev= n-1;prev>=-1;prev--){
    int include = 0;

        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1  + dp[curr+1][curr+1]; //***change
        }
        int exclude = 0 + dp[curr+1][prev+1]; //***change

        dp[curr][prev+1] =  max(include, exclude);

        }
    }

return dp[0][0];
    }


    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        // return solveMem(nums, n , 0, -1, dp);
        return lisTab(nums);



    }
};