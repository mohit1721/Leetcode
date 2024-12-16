class Solution {
public:
    int solve(vector<vector<int>>& grid , int m,int n, int i,int j, vector<vector<int>> &dp)
    {
        if(i==m-1 && j==n-1 && grid[i][j]==0)
        {
            return 1;
        }

        if( i<0 || j<0 || i>=m || j>=n || grid[i][j]==1)
         return 0;

        if(dp[i][j] != -1 ) 
            return dp[i][j];

        int down=0, right=0;

        if(grid[i][j]==0 && i>=0 && j>=0 && i<=m-1 && j<=n-1 )
        {
            down = solve(grid,m,n,i+1,j, dp);
            right= solve(grid,m,n,i,j+1, dp);
        }
        return dp[i][j]= down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
                return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(obstacleGrid,m,n, 0, 0, dp);
    }
};