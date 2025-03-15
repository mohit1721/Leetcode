class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProd = nums[0], minProd = nums[0], result = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) 
            swap(maxProd, minProd);  // Swap because multiplying by negative flips min & max

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = max(result, maxProd);
    }

    return result;
    }
};