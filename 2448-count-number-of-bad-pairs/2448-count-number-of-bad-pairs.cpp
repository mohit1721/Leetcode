class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int diff = i - nums[i];
            goodPairs += freq[diff];  // Count how many times this diff has appeared
            freq[diff]++;
        }
        
        return totalPairs - goodPairs;

    }
};