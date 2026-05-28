class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        int count = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(i , j, vis, grid);
                }
            }
        }

        return count;
    }

    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>&grid) {
        vis[i][j] = true;
        int rows = vis.size();
        int cols = vis[0].size();

        // go up

        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == '1') {
            dfs(i-1, j, vis, grid);
        }

        // go down
        if(i+1 < rows && !vis[i+1][j] && grid[i+1][j] == '1') {
            dfs(i+1, j, vis, grid);
        }

        // go left
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == '1') {
            dfs(i, j-1, vis, grid);
        }

        // go right
        if(j+1 < cols && !vis[i][j+1] && grid[i][j+1] == '1') {
            dfs(i, j+1, vis, grid);
        }
    }
};