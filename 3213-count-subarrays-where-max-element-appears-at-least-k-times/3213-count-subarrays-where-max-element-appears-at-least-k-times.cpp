class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // 1. find max element
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        // 2.find subarray till maxi found
        int s=0;
        int e=0;
        int count=0;
      long long int maxCount=0;
    
        while(e<n)
        {
            if(nums[e]==maxi) count++;
            while(count>=k)//valid
            {
                maxCount+=n-e;//uske aage k sb valid subarray hi hoga
                // aur
                if(nums[s]==maxi) count--;
                
                s++;
            }
               
            

             e++;
            
        }



        return maxCount;
    }
};