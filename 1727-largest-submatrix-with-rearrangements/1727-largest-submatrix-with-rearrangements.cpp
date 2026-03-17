class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>grid(rows, vector<int>(cols, 0));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++){
                if(i == 0) {
                    grid[i][j] = matrix[i][j];
                } else if(matrix[i][j] == 0){
                    grid[i][j] = 0;
                } else if(matrix[i][j] == 1) {
                    grid[i][j] = grid[i-1][j] + 1;
                }
            }

        }
        int ans = INT_MIN;
        for(int i=0;i<rows;i++) {
            vector<int>gridRow = grid[i];
            sort(gridRow.begin(), gridRow.end(), greater());
            for(int j=0;j<cols;j++) {
                ans = max(ans, gridRow[j]*(j+1));
            }
        }

        return ans;
    }
};