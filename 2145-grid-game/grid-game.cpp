class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topRowSum =0;
        for(int i=0;i<grid[0].size();i++)
        {
            topRowSum+=grid[0][i];
        }
        long long bottomRowSum=0, res=LLONG_MAX;
        for(int i=0;i<grid[0].size();i++)
        {
            topRowSum-= grid[0][i];//First Robot\U0001f916 pick from first row
            res = min(res, max(topRowSum, bottomRowSum )); // Minimize the maximum score for the second robot \U0001f916
            bottomRowSum+= grid[1][i];
        }
        return res;




    }
};