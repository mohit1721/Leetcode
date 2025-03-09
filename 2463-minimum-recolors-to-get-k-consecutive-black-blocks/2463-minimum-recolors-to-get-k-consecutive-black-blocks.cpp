class Solution {
public:
   int minimumRecolors(string& blocks, int k) {
    int n = blocks.size();
    int low = 0, high = 0, windowsize = k;
    
    int whiteCount = 0, minOperations = INT_MAX;

    while (high < n) {
        // Include current block in window
        if (blocks[high] == 'W') {
            whiteCount++;
        }

        // Step 1: Expand window until it reaches size 'k'
        if (high - low + 1 < windowsize) {
            high++;
        } 
        // Step 2: Process the window
        else {
            minOperations = min(minOperations, whiteCount);

            // Remove outgoing element (shrink window)
            if (blocks[low] == 'W') {
                whiteCount--;
            }
            
            low++;
            high++;
        }
    }

    return minOperations;
}

};