class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int distinctW=st.size();
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        unordered_map<int, int>subSt;//not set...esa DS ko unique ko rkhe taki agle subarrays k liye element mile..but also uniuqe v rhe usme.. Taking MAP..dono ho jayega**
        while(r<n){
            subSt[nums[r]]++;//

            while(subSt.size()==distinctW){//
               count+=(n-r);//
            //    slide
            // before slide take care of left element
        subSt[nums[l]]--;
        //GLTI++Yahan tum subSt[nums[l]]-- kar rahe ho, lekin agar kisi element ka count 0 ho gaya, to map se usse erase nahi kar rahe ho.
        //FIX:
        if(subSt[nums[l]]==0)
        {
            subSt.erase(nums[l]);
        }
        // slided
        l++;
        //
            }
r++;

        }


return count;

    }
};