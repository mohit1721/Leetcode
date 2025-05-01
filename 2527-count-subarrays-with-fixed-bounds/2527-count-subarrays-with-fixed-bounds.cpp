class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;

        int minKPos = -1;
        int maxKPos = -1;
        int problematicPos = -1; // indexes
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // CHECK OUT OF RANGE H to -> problematic idx
            if (nums[i] < minK || nums[i] > maxK) {

                problematicPos = i;
            }
            // else check of other two positions
            if (nums[i] == minK)
                minKPos = i;
            if (nums[i] == maxK) {
                maxKPos = i;
            }
            // calculate result on each iteration
            int smallerOfMin_MaxKPos = min(minKPos, maxKPos);
            // number of subarray will
            int numOfSubarrays = smallerOfMin_MaxKPos - problematicPos;

            // if its negative, means no favourable subarray[0] ->
            // culprit/problematicPos subarray k bich m hoga
            result += (numOfSubarrays < 0) ? 0 : numOfSubarrays;
        }

        return result;
    }
};