class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int topFirstRow = -1, bottomFirstRow = -1, leftFirstColumn = -1, rightFirstColumn = -1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    topFirstRow = i;
                    break;
                }
            }
            if(topFirstRow != -1){
                break;
            }
        }

        for(int i=grid.size()-1;i>=0;i--){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    bottomFirstRow = i;
                    break;
                }
            }
            if(bottomFirstRow != -1){
                break;
            }
        }

        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i] == 1){
                    leftFirstColumn = i;
                    break;
                }
            }
            if(leftFirstColumn != -1){
                break;
            }
        }
        
        for(int i=grid[0].size()-1;i>=0;i--){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i] == 1){
                    rightFirstColumn = i;
                    break;
                }
            }
            if(rightFirstColumn != -1){
                break;
            }
        }
        
        if(topFirstRow == -1){
            return 0;
        }

        return (bottomFirstRow - topFirstRow + 1)*(rightFirstColumn - leftFirstColumn + 1);
    }
};