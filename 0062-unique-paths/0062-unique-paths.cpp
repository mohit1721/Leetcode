class Solution {
public:

    int solve(int m,int n, int i,int j, vector<vector<int>> &dp)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
    if(dp[i][j] != -1 ) return dp[i][j];
    int down=0, right=0;

    if(i>=0 && j>=0 && i<m && j<n)
    {
        down = solve(m,n,i+1,j, dp);
        right= solve(m,n,i,j+1, dp);
    }
        
        return dp[i][j]= down+right;


    }

    int uniquePaths(int m, int n) {

vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return solve(m,n,0,0,dp);

    }


};