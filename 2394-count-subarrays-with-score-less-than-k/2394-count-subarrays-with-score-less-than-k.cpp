class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       long long result=0, sum=0;
       int n= nums.size();
       int i=0 , j=0;
       while(j<n){
            sum+=nums[j];
            while(i<=j && sum *(j-i+1) >= k){ //invalid , shrink from left
                sum-=nums[i];
                i++;

            }
            //valid 
            result+= (j-i+1);
            j++;
       }
      
return result;


        
    }
};