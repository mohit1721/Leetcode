class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
      int rows = moveTime.size();
        int cols = moveTime[0].size();

        // 3D vector to store minimum time for each cell and parity
        vector<vector<vector<int>>> minTime(rows, vector<vector<int>>(cols, vector<int>(2, INT_MAX)));
        
        // Starting point
        minTime[0][0][0] = 0;
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> priorityQueue;
        priorityQueue.push({0, 0, 0, 0}); // {currentTime, row, col, parity}
        
        // Directions for moving right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!priorityQueue.empty()) {
            vector<int> current = priorityQueue.top();
            priorityQueue.pop();
            
            int currentTime = current[0];
            int row = current[1];
            int col = current[2];
            int parity = current[3];

            // If current time is greater than recorded time, skip
            if (currentTime > minTime[row][col][parity]) continue;

            // Explore all possible directions
            for (auto& direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                // Check boundaries
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    // Calculate the next time to reach the new cell
                    int nextTime = max(currentTime, moveTime[newRow][newCol]) + (parity == 0 ? 1 : 2);

                    // If the new time is less than the previously recorded time for the new cell
                    if (nextTime < minTime[newRow][newCol][1 - parity]) {
                        minTime[newRow][newCol][1 - parity] = nextTime;
                        priorityQueue.push({nextTime, newRow, newCol, 1 - parity});
                    }
                }
            }
        }

        // Return the minimum time to reach the bottom-right corner
        return min(minTime[rows - 1][cols - 1][0], minTime[rows - 1][cols - 1][1]);
        
    }
};