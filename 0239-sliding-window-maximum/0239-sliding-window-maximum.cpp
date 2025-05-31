class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        list<int> maxElements;
        vector<int> ans;
        int l = 0, r = 0;
        while (r < n) {
            while (!maxElements.empty() &&
                   maxElements.back() <
                       nums[r]) { // maxStore kr rhe , to max hi rkho, chhote ko
                                  // q rkhna**
                maxElements.pop_back(); //
            }

            maxElements.push_back(nums[r]);

            if (r - l + 1 < k) {
                r++;
            } else { // got window
                int maxElementInCurrentWindow = maxElements.front();
                ans.push_back(maxElementInCurrentWindow);
                // slide..
                if (maxElementInCurrentWindow == nums[l]) {
                    maxElements.pop_front();
                }
                l++;
                r++;
            }
        }
        return ans;
    }
};