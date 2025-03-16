class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        list<int>maxElements;
        vector<int>ans;
        int l=0,r=0;
        while(r<n)
        {
            // do calc. but before check for right position to insert [as I need to maintain the maxElements in list]
            while(!maxElements.empty() && maxElements.back() < nums[r] )
                maxElements.pop_back();//
            
            // then push the current ele
            maxElements.push_back(nums[r]);

            // if not in Wsize
            if(r-l+1 < k)
            {
                r++;
            }
            else {
                // >=
                int maxElementInCurrentWindow = maxElements.front();
                ans.push_back(maxElementInCurrentWindow);
                // also , before sliding, check the left part of window yaani nums[s], that kya jo abhi ka maxElementInCurrentWindow hi to nhi h jisko hatana h
                if(maxElementInCurrentWindow == nums[l])
                {
                    maxElements.pop_front();//age m rhega obv. [maxElement h to].qki algorith hi waisa  ki maxElement front m hi hpga.
                }
                // now u can slide
                l++;
                r++;

            }

        }
        return ans;
    }
};