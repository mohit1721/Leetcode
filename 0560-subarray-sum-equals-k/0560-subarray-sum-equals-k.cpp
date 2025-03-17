class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int prefixSum=0;
        unordered_map<int,int>mp;
        // 
        mp[0]=1;
         for(int i=0;i<=n-1;i++)
        {
            // 
            prefixSum+=nums[i];
            if(mp.count(prefixSum-k)) //-----
            {
                count+=mp[prefixSum-k];
            }
            // 
            mp[prefixSum]++;
        }
return count;
    }
};