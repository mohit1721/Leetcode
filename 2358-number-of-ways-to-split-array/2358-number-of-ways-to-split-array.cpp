class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
// 10 14 6 13 suffix. at i
// 13 3 -1 7  prefix. at  n-i-1

int n = nums.size();
vector<long long int>prefixSum(n);
vector<long long int>suffixSum(n);

 suffixSum[0] = nums[0];
for(int i=1;i<n;i++)
{
   
    suffixSum[i]= suffixSum[i-1] + nums[i];
}
prefixSum[n-1] = nums[n-1];
for(int i=n-2;i>=0;i--)
{
    prefixSum[i] = prefixSum[i+1]+nums[i];
}

int cnt=0;
// 10 14 6 13 suffix. at i
// 13 3 -1 7  prefix. at  n-i-1

    for(int i=0;i<n-1;i++)
    {
        if(suffixSum[i]>= prefixSum[i+1] )
        {
            cnt++;
        }
    }

return cnt;
    }
};