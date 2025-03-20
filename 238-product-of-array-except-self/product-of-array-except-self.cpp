class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prefix=1;
        vector<int>ans(n,1);//
        for(int i=0;i<n;i++)
        {
            ans[i]*=prefix;//Pehle se jo prefix hai, usko store karenge
            prefix*=nums[i];//update prefix
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=suffix;
            suffix*=nums[i];//update
        }
        return ans;
    }
};