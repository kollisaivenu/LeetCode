class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>grid(rows, vector<int>(cols, 0));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++){
                if(i == 0) {
                    grid[i][j] = matrix[i][j] - '0';
                } else if(matrix[i][j] == '0'){
                    grid[i][j] = 0;
                } else if(matrix[i][j] == '1') {
                    grid[i][j] = grid[i-1][j] + 1;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                for(int k=0;k<=j;k++) {
                    int height = INT_MAX;
                    for(int l=k;l<=j;l++) {
                        height = min(height, grid[i][l]);
                    }
                    ans = max(ans, (j-k+1)*height);
                }
            }
        }

        return ans;
    }

};