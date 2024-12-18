class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
       int maxLen=0;
       int cnt=0;
        for(int i=0;i<n;i++)
        {
         
            if(nums[i]==1)
            {
                cnt++;
               
            }
            else{ // non-continious
                cnt=0;
            }
            //update always
             maxLen = max(maxLen, cnt);
        }
return maxLen;

    }
};