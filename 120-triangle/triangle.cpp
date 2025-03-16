class Solution {
public:
    int solve(vector<vector<int>>& grid,int n, int m ,int i, int j, vector<vector<int>>&dp )
    {
        //reached dest. ..last ROW.. [not any specific cell]
        if(i==n-1) return grid[i][j];
        // if not in boundary
        // if(i<0||j<0||i>=n||j>=m) return 0;


         if(dp[i][j] != -1) return dp[i][j];
    
      
           int down  =  grid[i][j] + solve(grid, n,m, i+1, j, dp);
           int diag =   grid[i][j]  + solve(grid, n,m,i+1, j+1, dp);
             
    
        return dp[i][j] = min(down , diag) ;
    }
    int minimumTotal(vector<vector<int>>& grid) {
        // similar to minimum falling path sum..exact
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); //
        return solve(grid,n,m,0,0,dp);//
        
    }
};