class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        int count = 0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int area = 0;
                    dfs(i , j, vis, grid, area);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }

    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>&grid, int& area) {
        area++;
        vis[i][j] = true;
        int rows = vis.size();
        int cols = vis[0].size();

        // go up

        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1) {
            dfs(i-1, j, vis, grid, area);
        }

        // go down
        if(i+1 < rows && !vis[i+1][j] && grid[i+1][j] == 1) {
            dfs(i+1, j, vis, grid, area);
        }

        // go left
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1) {
            dfs(i, j-1, vis, grid, area);
        }

        // go right
        if(j+1 < cols && !vis[i][j+1] && grid[i][j+1] == 1) {
            dfs(i, j+1, vis, grid, area);
        }
    }
};