class Solution {
public:
    int solve(vector<int>&nums, int n, int startIndex, int lastIndex, vector<int>&dp){
        if(startIndex>lastIndex) return 0;// 

        if(dp[startIndex] != -1) return dp[startIndex];

        int robed = nums[startIndex] + solve(nums, n, startIndex+2, lastIndex,dp);
        int notRobbed = 0 + solve(nums, n, startIndex+1, lastIndex,dp);

        return dp[startIndex] = max(robed, notRobbed);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
       vector<int>dp1(n+1,-1);
       vector<int>dp2(n+1,-1);
       if(n==1) return nums[0];//edge case
        int option1 = solve(nums, n, 0 , n-2,dp1);
        int option2 = solve(nums, n, 1, n-1, dp2);

        return max(option1, option2);
    }
};