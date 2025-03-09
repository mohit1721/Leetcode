class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();

    // Extend array for circular wrap-around
    for (int i = 0; i < k - 1; i++) {
        colors.push_back(colors[i]);
    }

    int result = 0;
    int low = 0, high = 1; // Start from 1 since we compare high-1 with high
    int count = 1; // To track alternating sequence length

    while (high < n + k - 1) {
        // If alternating condition breaks, reset count and update low
        if (colors[high] == colors[high - 1]) {
            count = 1; // Restart count
            low = high; // Start new window
        } else {
            count++; // Extend alternating sequence
        }

        // Check if window of size `k` is reached
        if (count == k) {
            result++;
            count--; // Slide window forward
        }

        high++;
    }

    return result;
}


};