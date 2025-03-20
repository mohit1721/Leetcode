class Solution {
public:
/*
Approach:
if continuous '0' is 1 then count 1
if continuous '0' is 2 then count 2+1 = 3
if continuous '0' is 3 then count 3+2+1 = 6
if continuous '0' is 4 then count 4+3+2+1 = 10
*/
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeroCount=0;
        long long ans =0;
       
        for(int num: nums)
        {
            if(num==0)
            {
                //continuous
                zeroCount++;
                ans= ans + zeroCount;
            }
            else{
                zeroCount=0;//new subarray starting
            }
        }
        return ans;
    }
};