class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // approach.
        // rowwise cnt, columnwise count servers, & check if counts >=2 , add to result
        int n=grid.size();
        int m=grid[0].size();
        vector<int>rowWiseServersCnt(n,0);
        vector<int>columnWiseServersCnt(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    rowWiseServersCnt[i]+=1;
                    columnWiseServersCnt[j]+=1;
                }

            }
        }
        // ab jiske cnt>=2 , add to res

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1 && (rowWiseServersCnt[i]>=2 ||  columnWiseServersCnt[j]>=2 ))  
        {
            ans++;
        } 

    }
       
    }


return ans;
    }
};