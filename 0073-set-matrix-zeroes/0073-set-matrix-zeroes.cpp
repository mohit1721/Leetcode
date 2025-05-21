class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // sb 0's k co-ordinates store kr lo rk baar
        queue<pair<int, int>> q;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // ab
        while (!q.empty()) {
            auto fnode = q.front();
            q.pop();
            int X = fnode.first;
            int Y = fnode.second;
            
            for (int i = 0; i < m; i++) {
                if (matrix[X][i] != 0)
                    matrix[X][i] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[j][Y] != 0)
                    matrix[j][Y] = 0;
            }
        }
    }
};