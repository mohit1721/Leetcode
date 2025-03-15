class Solution {
public:
int solve(vector<int>&freqArr, int idx, vector<int>&dp)
{
    int fSize = freqArr.size();

    if(idx >= fSize) return 0;
    if(dp[idx] != -1) return dp[idx];
// This problem is similar to the "House Robber" problem where we cannot take two adjacent numbers.

    int collectCurrEle = freqArr[idx] * idx + solve(freqArr, idx + 2, dp);
    int skipCurrEle = 0 + solve(freqArr, idx + 1, dp);

    return dp[idx]= max(collectCurrEle, skipCurrEle);



}


    int deleteAndEarn(vector<int>& nums) {
        
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int>freqArr(maxElement+1 , 0);
        // calculate the freq.
        for(int num: nums)
        {
            freqArr[num]++;
        }
        vector<int>dp(maxElement+1, -1);

    // NOTE: not iterating in nums Array , + not considering the nums array element ...here the index is the itself element....
        return solve(freqArr, 0 , dp); //


        
    }
};