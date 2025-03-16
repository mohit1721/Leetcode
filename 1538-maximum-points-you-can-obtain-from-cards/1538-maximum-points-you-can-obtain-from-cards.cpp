class Solution {
public:
    int maxScore(vector<int>& cards, int K) {
          int N = cards.size();
        int totalSum = 0;

        // Step 1: Compute total sum of all cards
        for (int num : cards) {
            totalSum += num;
        }

        // Edge case: If K == N, return the total sum (pick all cards)
        if (K == N) return totalSum;

        // Step 2: Find the minimum sum of a window of size (N-K)
        int windowSize = N - K;
        int low = 0, high = 0;
        int minWindowSum = INT_MAX, currentWindowSum = 0;

        while (high < N) {
            // Step 1: Expand the window until it reaches the required size
            if (high - low + 1 < windowSize) {
                currentWindowSum += cards[high]; // Add new element
                high++;
            } 
            // Step 2: Process and Slide the window
            else {
                // Step 2a: Process the window
                currentWindowSum += cards[high]; // Add last element
                minWindowSum = min(minWindowSum, currentWindowSum);

                // Step 2b: Slide the window (remove leftmost element)
                currentWindowSum -= cards[low]; 
                low++;  
                high++; 
            }
        }

        // Step 3: Maximum score = Total sum - Minimum window sum
        return totalSum - minWindowSum;
    }
};