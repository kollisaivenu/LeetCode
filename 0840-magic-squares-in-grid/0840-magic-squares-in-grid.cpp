class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int startRow = 1, endRow = grid.size()-2, startCol = 1, endCol = grid[0].size()-2;
        int ans = 0;
        for(int i=startRow;i<=endRow;i++) {
            for(int j=startCol;j<=endCol;j++) {
                if(grid[i][j] == 5) {
                    vector<bool>isPresent(10, false);
                    isPresent[grid[i][j]] = true;
                    if(grid[i-1][j] + grid[i+1][j] == 10) {
                        isPresent[grid[i-1][j]] = true;
                        isPresent[grid[i+1][j]] = true;
                    } else {
                        continue;
                    }

                    if(grid[i][j-1] + grid[i][j+1] == 10) {
                        isPresent[grid[i][j-1]] = true;
                        isPresent[grid[i][j+1]] = true;
                    } else {
                        continue;
                    }

                    if(grid[i-1][j-1] + grid[i+1][j+1] == 10) {
                        isPresent[grid[i-1][j-1]] = true;
                        isPresent[grid[i+1][j+1]] = true;
                    } else {
                        continue;
                    }

                    if(grid[i-1][j+1] + grid[i+1][j-1] == 10) {
                        isPresent[grid[i-1][j+1]] = true;
                        isPresent[grid[i+1][j-1]] = true;
                    } else {
                        continue;
                    }

                    if((grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1]) != 15) {
                        continue;
                    }

                    if((grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1]) != 15) {
                        continue;
                    }

                    if((grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1]) != 15) {
                        continue;
                    }

                    if((grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1]) != 15) {
                        continue;
                    }

                    bool magicGrid = true;
                    for(int k=1;k<=9;k++) {
                        if(!isPresent[k]) {
                            magicGrid = false;
                            break;
                        }
                    }

                    if(magicGrid) {
                        ans++;
                    }
                    
                }
            }
        }

        return ans;
    }
};