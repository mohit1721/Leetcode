class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        //reached the dest. 
        if(i==n-1 && j==m-1) return grid[i][j]; 
        // if out of boundary
        if(i<0 || j<0 || i>n || j> m) return INT_MAX;//since need min.

        if(dp[i][j] != -1) return dp[i][j];
        int down = INT_MAX, right = INT_MAX;

int minSum=INT_MAX;
        // if within boundary
        if( i+1<n )
        {
            down = grid[i][j] + solve(grid, i+1, j, m , n, dp);
            minSum = min(minSum, down);
        }
        if(j+1<m)
        {
            right = grid[i][j] + solve(grid, i, j+1, m, n, dp);
            minSum = min(minSum, right);
        }

return dp[i][j] = minSum;
    }
    int minPathSum(vector<vector<int>>& grid) {
        // just read qn.
    int n = grid.size();
    int m = grid[0].size();
    int result = INT_MAX;
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    return min(result, solve(grid, 0 , 0 , m, n, dp));
    }
};