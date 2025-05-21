class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    long long maxSum=0;
    int n=nums.size();
    int i=0,j=0;
    long long sum=0;
    unordered_map<int,int>freq;

    while(j<n){

            freq[nums[j]]++;
            sum+=nums[j];

        if(j-i+1 > k ){
            freq[nums[i]]--;

            if(freq[nums[i]]==0 )
                freq.erase(nums[i]);

            sum-=nums[i];
            i++;


        }

     if(j-i+1==k && freq.size() == k)
     {
        maxSum = max(maxSum, sum);

     }
j++;

    }      
    return maxSum;



    }
};