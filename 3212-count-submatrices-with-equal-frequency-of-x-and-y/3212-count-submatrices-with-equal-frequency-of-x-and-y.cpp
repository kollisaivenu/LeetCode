class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>x(rows, vector<int>(cols, 0));
        vector<vector<int>>y(rows, vector<int>(cols, 0));

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(i == 0) {
                    if(grid[i][j] == 'X') {
                        x[i][j] = 1;
                    } else {
                        x[i][j] = 0;
                    }
                } else if(grid[i][j] == 'X') {
                    x[i][j] = x[i-1][j] + 1;
                } else {
                    x[i][j] = x[i-1][j];
                }
            }
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(i == 0) {
                    if(grid[i][j] == 'Y') {
                        y[i][j] = 1;
                    } else {
                        y[i][j] = 0;
                    }
                } else if(grid[i][j] == 'Y') {
                    y[i][j] = y[i-1][j] + 1;
                } else {
                    y[i][j] = y[i-1][j];
                }
            }
        }

        int count = 0;
        for(int i=0;i<rows;i++) {
            int totalX = 0, totalY = 0;
            for(int j=0;j<cols;j++) {
                totalX += x[i][j];
                totalY += y[i][j];
                if(totalX == totalY && totalX > 0) {
                    count++;
                }
                
            }
        }

        return count;
        
    }
};