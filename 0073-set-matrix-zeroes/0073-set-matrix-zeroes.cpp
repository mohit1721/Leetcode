class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        int n=matrix.size();
        int m=matrix[0].size();
// push all 0 wale co-ordinates
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        // do bfs
        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            int newX = fnode.first;
            int newY = fnode.second;
            //mark that row, if any non-zero
            for(int i=0;i<m;i++){
                if(matrix[newX][i]!=0){
                    matrix[newX][i]=0;
                }
            }
            // mark that col
            for(int j=0;j<n;j++){
                if(matrix[j][newY]!=0){
                    matrix[j][newY]=0;
                }
            }
        }






// return matrix;


    }
};