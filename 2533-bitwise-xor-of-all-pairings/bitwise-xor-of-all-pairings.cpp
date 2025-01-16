class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int k=0;
         int res=0;
         unordered_map<int,long long int>mp; //nums1 ka element -> m times , & vice-versa
        for(int &num : nums1)
        {
            mp[num]+=m;
        }
        // similarly for nums2
        for(int &num : nums2)
        {
            mp[num]+=n;
        }
        // 
        for(auto &x: mp)
       {
        int num = x.first;
       long long int freq=x.second;
        // jiska sirf odd freq hoga wohi bachega..baki 0
        if(freq %2 ==1)
        {
            res^=num;
        }


       }

      
        return res;
    }
};