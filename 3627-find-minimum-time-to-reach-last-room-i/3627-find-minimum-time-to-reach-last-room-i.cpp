class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
    int n= moveTime.size();
    int m=moveTime[0].size();
    // Directions for moving to adjacent rooms
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
    // Priority Queue (min-heap) to store the current time, row, col
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 0}); // Starting from (0,0) at time = 0
    // 2D vector to track minimum time to reach each cell
    vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
    minTime[0][0] = 0;
    while (!pq.empty()) {
        auto [current_time, row, col] = pq.top();
        pq.pop();
        // If we reach the bottom-right corner
        if (row == n - 1 && col == m - 1) {
            return current_time;
        }
        for (auto [dx, dy] : directions) {
            int newRow = row + dx;
            int newCol = col + dy;
            // Check if the new position is within bounds
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                int waitTime = moveTime[newRow][newCol] + 1 ; //****
                int reachTime = max(current_time + 1, waitTime);
                // Only push to pq if we found a faster way to reach new cell
                if (reachTime < minTime[newRow][newCol]) {
                    minTime[newRow][newCol] = reachTime;
                    pq.push({reachTime, newRow, newCol});
                }
            }
        }
    }
    // If unreachable, though problem constraints ensure a solution exists
    return -1;
    }
};