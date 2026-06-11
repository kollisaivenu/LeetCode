class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>>q;
        int rows = grid.size();
        int cols = grid[0].size();
        int mins = 0;
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), 0));
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int, int>, int>p = q.front();
            q.pop();
            int x = p.first.first;
            int y = p.first.second;
            mins = p.second;

            if(x-1 >= 0 && grid[x-1][y] == 1 && vis[x-1][y] == false) {
                vis[x-1][y] = true;
                q.push(make_pair(make_pair(x-1, y), mins+1));
            }

            if(y-1 >= 0 && grid[x][y-1] == 1 && vis[x][y-1] == false) {
                vis[x][y-1] = true;
                q.push(make_pair(make_pair(x, y-1), mins+1));
            }

            if(x+1 < rows && grid[x+1][y] == 1 && vis[x+1][y] == false) {
                vis[x+1][y] = true;
                q.push(make_pair(make_pair(x+1, y), mins+1));
            }

            if(y+1 < cols && grid[x][y+1] == 1 && vis[x][y+1] == false) {
                vis[x][y+1] = true;
                q.push(make_pair(make_pair(x, y+1), mins+1));
            }
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j] == 1 && vis[i][j] == false) {
                    return -1;
                }
            }
        }

        return mins;
    }
};