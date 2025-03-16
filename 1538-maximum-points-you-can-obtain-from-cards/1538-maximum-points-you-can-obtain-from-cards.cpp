class Solution {
public:
    int maxScore(vector<int>& cards, int K) {
        
   int N = cards.size();
    
    // Step 1: Compute the prefix sum and suffix sum arrays
    vector<int> prefix(K + 1, 0); // Prefix sum for first K cards
    vector<int> suffix(K + 1, 0); // Suffix sum for last K cards
    
    // Compute prefix sum for the first K cards
    for (int i = 1; i <= K; ++i) {
        prefix[i] = prefix[i - 1] + cards[i - 1];
    }
    
    // Compute suffix sum for the last K cards
    for (int i = 1; i <= K; ++i) {
        suffix[i] = suffix[i - 1] + cards[N - i];
    }
    
    // Step 2: Try picking x cards from the front and K - x from the back
    int maxScore = 0;
    for (int x = 0; x <= K; ++x) {
        int currentScore = prefix[x] + suffix[K - x];
        maxScore = max(maxScore, currentScore);
    }
    
    return maxScore;

        
    }
};