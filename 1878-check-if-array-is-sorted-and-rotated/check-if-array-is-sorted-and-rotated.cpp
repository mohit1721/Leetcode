class Solution {
public:
    bool check(vector<int>& nums) {
       int count=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
           if(nums[i]>nums[(i+1)%n])
           {
               count++;
           }
       } 
        // if(nums[n-1]>nums[0])
        //     count++;
        // return count<=1;
        if(count>1) 
        return false;

        return true;
        
        
    }
};