class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // similar to max. product subarray
        long long subArrayCounts = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int NoOfPairs = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            // invalid/ do calculation
            NoOfPairs += mp[nums[j]];
            // freq +
            mp[nums[j]]++;

            // while/if valid..shrink, by calculating the ans[]
            while (NoOfPairs >= k) {
                // ans. calc.
                subArrayCounts +=
                    (n - j); //**VVVVVVI STEP ...// All subarrays from
                             //[left..right] to [left..n-1] are valid
                // shrinking window
                mp[nums[i]]--;
                NoOfPairs -= mp[nums[i]]; // left wale element k wjh sejo pairs
                                          // bne uski count v ghategi, similar
                                          // step in max. product subarray
                i++; //
            }
            j++; // always inc.
        }

        return subArrayCounts;
    }
};