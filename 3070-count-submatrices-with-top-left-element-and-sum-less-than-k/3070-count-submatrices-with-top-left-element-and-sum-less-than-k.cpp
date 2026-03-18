class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>mat(rows, vector<int>(cols, 0));

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(i == 0) {
                    mat[i][j] = grid[i][j];
                } else {
                    mat[i][j] = mat[i-1][j] + grid[i][j];
                }
            }
        }
        int count = 0;
        for(int i=0;i<rows;i++) {
            int sum = 0;
            for(int j=0;j<cols;j++) {
                sum += mat[i][j];

                if(sum <= k) {
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};