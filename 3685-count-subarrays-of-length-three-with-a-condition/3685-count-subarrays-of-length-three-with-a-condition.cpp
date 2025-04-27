class Solution {
public:
    int countSubarrays(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0;
    int count = 0;
    
    while (j < n) {
        // Once we have a window of size 3
        if (j - i + 1 == 3) {
            // Check the condition for the triplet nums[i], nums[i+1], nums[i+2]
            if ((nums[i] + nums[j] )*2== nums[i+1] ) {//---JAHIL ->
                count++;  // If the condition is met, increase the count
            }
            // Shift the window by moving 'i' forward
            i++;
        }
        // Always move 'j' forward to expand the window
        j++;
    }
    return count;
}

};