class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int oddCount = 0, result = 0;
        int validStarts = 0;

        while (j < nums.size()) {
            //#MAIN CONDITION: Check for odd element
            if (nums[j] & 1) {
                oddCount++;
                validStarts = 0;  // Reset jab new odd mile
            }

            //#SHRINKING WINDOW FROM LEFT SIDE
            while (oddCount == k) {
                validStarts++; // Count possible valid start points

                if (nums[i] & 1) {
                    oddCount--; // Reduce odd count while shrinking
                }

                i++; // Move left pointer
            }

            //#RESULT CALCULATION & J++
            result += validStarts;
            j++;
        }

        return result;
    }
};
