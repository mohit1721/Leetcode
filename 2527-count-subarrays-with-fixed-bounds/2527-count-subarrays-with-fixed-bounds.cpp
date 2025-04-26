class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long result=0;
 
       int minPos=-1;
       int maxPos=-1;
       int cultPos=-1;//indexes
       int n=nums.size();
      
    for(int i=0;i<n;i++)
    {
        // out of range-->culprit
        if(nums[i]<minK || nums[i]>maxK)
            cultPos=i;
        
        if(nums[i]==minK)
            minPos=i;
        if(nums[i]==maxK)
            maxPos=i; 

            //  and ,find result on each iteration
            int temp=min(minPos,maxPos)-cultPos;
            if(temp<0) temp=0;
            result+=temp;
    }

        return result;

    }
};