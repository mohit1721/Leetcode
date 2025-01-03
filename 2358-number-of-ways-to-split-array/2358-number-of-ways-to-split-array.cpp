class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
// 10 14 6 13 suffix. at i
// 13 3 -1 7  prefix. at  n-i-1
//opti.
int n = nums.size();
long long  totalSum =0;
for(int num : nums)
{
    totalSum+=num;
}


long long  prefixSum=0;
int ways =0;
for(int i=0;i<n-1;i++)
{
    prefixSum+=nums[i];
   long long  rightSum = totalSum- prefixSum;
    if(prefixSum >= rightSum)
        ways++;

} 

return ways;


    }
};