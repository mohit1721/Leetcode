class Solution {
public:


   // Function to check if it's possible to split the array into 'k' subarrays with maximum sum <= target
bool canSplit(const vector<int>& nums, int k, int target) {
    int currentSum = 0;
    int subarrays = 1; // At least one subarray is required

    for (int num : nums) {
        if (currentSum + num > target) {
            subarrays++;
            currentSum = num; // Start a new subarray with the current number
            if (subarrays > k) {
                return false;
            }
        } else {
            currentSum += num;
        }
    }
    return true;
}

// Main function to find the minimized largest sum
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());  // The largest element in the array
    int high = accumulate(nums.begin(), nums.end(), 0); // The sum of all elements in the array

    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (canSplit(nums, k, mid)) {
            high = mid;  // Try to find a smaller maximum sum
        } else {
            low = mid + 1;  // Increase the minimum sum as the current mid is not feasible
        }
    }

    return low;
}

};