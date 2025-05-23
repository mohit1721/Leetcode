class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(int &x : nums){
            auto it = lower_bound(lis.begin(), lis.end(), x ); ///lis
            if(lis.empty() || it == lis.end()){
                lis.push_back(x);
            }
            else{
                *it = x;
            }

        }

        return lis.size();
    }
};