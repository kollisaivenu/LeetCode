class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size()-1;
        int ans = 0;
        vector<vector<int>>grid(row, vector<int>(col, 0));

        while(low<=high) {
            int mid = low+(high-low)/2;
            if(validate(mid, grid, cells, ans)) {
                //changeGrid(grid, cells, mid, ans);
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ans+1;
    }

    void changeGrid(vector<vector<int>>&grid, vector<vector<int>>&cells, int mid, int lastAns) {
        for(int i=lastAns;i<=mid;i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1; 
        }
    }
    bool validate(int mid, vector<vector<int>>grid, vector<vector<int>>&cells, int lastAns) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<=mid;i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1; 
        }

        vector<vector<bool>>visited(row, vector<bool>(col, false));
        bool possible = false;
        for(int i=0;i<col;i++){
            if(grid[0][i] == 0) {
                visited[0][i] = true;
                possible = possible || doesPathExist(grid, 0, i, visited);
                //visited[0][i] = false;
            }
            
        }

        return possible;
    }
    bool doesPathExist(vector<vector<int>>& grid, int currentRow, int currentColumn, vector<vector<bool>>&visited) {
        int row = grid.size();
        int col = grid[0].size();

        if(currentRow == row-1) {
            return true;
        }

        bool possible = false;
        if(currentRow + 1 < row && grid[currentRow+1][currentColumn] == 0 && visited[currentRow+1][currentColumn] == false) {
            visited[currentRow+1][currentColumn] = true;
            possible = possible || doesPathExist(grid, currentRow+1, currentColumn, visited);
            //visited[currentRow+1][currentColumn] = false;
        }

        if(currentRow - 1 >= 0 && grid[currentRow-1][currentColumn] == 0 && visited[currentRow-1][currentColumn] == false) {
            visited[currentRow-1][currentColumn] = true;
            possible = possible || doesPathExist(grid, currentRow-1, currentColumn, visited);
            //visited[currentRow+1][currentColumn] = false;
        }

        if(currentColumn-1>=0 && grid[currentRow][currentColumn-1] == 0 && visited[currentRow][currentColumn-1] == false) {
            visited[currentRow][currentColumn-1] = true;
            possible = possible || doesPathExist(grid, currentRow, currentColumn-1, visited);
            //visited[currentRow][currentColumn-1] = false;
        }

        if(currentColumn+1<col && grid[currentRow][currentColumn+1] == 0 && visited[currentRow][currentColumn+1] == false) {
            visited[currentRow][currentColumn+1] = true;
            possible = possible || doesPathExist(grid, currentRow, currentColumn+1, visited);
            //visited[currentRow][currentColumn+1] = false;
        }

        return possible;
    }
};