class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // My Approach
        // Better Approach
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin() , nums.end());
        int lastSmaller = INT_MIN ; // not -1 since... arr contains -ve numbers also
        int cnt=0;
        int maxCons =1 ; //
        for(int i=0;i<n;i++)
        {
            //a[i] is the next element of the current sequence.
            if(nums[i] - 1 == lastSmaller)
            {
                cnt++;
                lastSmaller = nums[i];
            }
            // a[i] is not the next element of the current sequence*
        //means , starting new current sequence ...
            else if(nums[i] != lastSmaller)
            {
                cnt=1; // reinititialize cnt to 1
                lastSmaller = nums[i];//
            }
            //update the maxLen always
            maxCons = max(maxCons , cnt );
        }

     return maxCons;
        
    }
};