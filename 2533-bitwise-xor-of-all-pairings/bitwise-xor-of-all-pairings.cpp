class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int k=0;
         int res=0;
        //  unordered_map<int,long long int>mp; //nums1 ka element -> m times , & vice-versa

         if(m%2==1 && n%2==0)//agar dusra wla odd length h to , 
     {   for(int &num : nums1)
        {
           res^=num;
        }
        
        }
        // similarly for nums2
        if(n%2==1 && m%2==0)
       { for(int &num : nums2)
        {
            res^=num;
        }}
        // 
        if(n%2==1 && m%2==1)
        { for(int &num : nums1)
        {
           res^=num;
        }
         for(int &num : nums2)
        {
           res^=num;
        }

        }

      
        return res;
    }
};