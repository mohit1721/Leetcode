class Solution {
public:
   int majorityElement(vector<int>& nums) {
    // BOYER-MOORE VOTING ALGORITHM
    int n = nums.size();
    int assumedMajElement = nums[0];
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            assumedMajElement = nums[i];
            count = 1;
        } 
        else if (assumedMajElement == nums[i]) {
            count++;
        } 
        else {
            count--;
        }
    }
    return assumedMajElement;
}

};