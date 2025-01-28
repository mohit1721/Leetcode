class Solution {
public:
int n,m;
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
       
        // check boundaries
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] ==0 ) //jamin o thori machhli milega
        {
            return 0;
        }
         int maxFishFromThisLocation = grid[r][c];
         grid[r][c]=0;//mark that loc. to land..taki dobar na same loc p jaye
        // else 4 dirn
        maxFishFromThisLocation  += dfs(grid, r+1, c);
        maxFishFromThisLocation += dfs(grid, r-1, c);
        maxFishFromThisLocation += dfs(grid, r, c+1);
        maxFishFromThisLocation += dfs(grid, r, c-1);


return maxFishFromThisLocation;
    }


    int findMaxFish(vector<vector<int>>& grid) {
         n= grid.size();
         m=grid[0].size();
        int otimalFishes=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                // agar machhli[>0] h tbhi to dfs maroge
                if(grid[i][j] != 0)
                otimalFishes= max(otimalFishes, dfs(grid, i, j));
            }
        }
        return otimalFishes;
    }
};