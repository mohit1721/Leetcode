class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        // # 1
        sort(nums.begin(), nums.end());
        int prev = -1;
        int cnt = 0;
        int ans = -1;
        int n = nums.size();
        int maxFreq = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0) // agar even ho tabhi
            {
                //prev = nums[i];

                if (prev == nums[i]) {
                    cnt++;
                    
                } else {

                    if (cnt > maxFreq ||
                        (cnt == maxFreq &&
                         ans > prev)) // this line for --> If there is a tie,
                                      // return the smallest one.
                    { // maximize it,
                        maxFreq = cnt;
                        ans = prev;
                    }

                    prev = nums[i];
                    cnt = 1; // re-initialize
                }
            }
        }
            // Final update for the last number ---> ????
            if(cnt > maxFreq || (cnt == maxFreq && (prev < ans)) )

            {
                ans = prev;
            }

        return ans;
    }
};