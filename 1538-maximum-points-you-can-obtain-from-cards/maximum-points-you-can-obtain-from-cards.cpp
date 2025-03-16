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
    int minWindowSum = INT_MAX, currentWindowSum = 0;

    // Compute the first window sum
    for (int i = 0; i < windowSize; ++i) {
        currentWindowSum += cards[i];
    }
    minWindowSum = currentWindowSum;

    // Slide the window across the array
    for (int i = windowSize; i < N; ++i) {
        currentWindowSum += cards[i] - cards[i - windowSize];
        minWindowSum = min(minWindowSum, currentWindowSum);
    }

    // Step 3: Maximum score = Total sum - Minimum window sum
    return totalSum - minWindowSum;

        
    }
};