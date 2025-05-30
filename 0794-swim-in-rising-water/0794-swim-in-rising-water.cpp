class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int rows = grid.size();
        int cols = grid[0].size();
        int ans;
        vector<vector<int>>vis(rows, vector<int>(cols, 0));

        pq.push(make_pair(grid[0][0], make_pair(0, 0)));
        vis[0][0] = 1;
        


        while(!pq.empty()){
            int height = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == rows-1 && y == cols-1){
                ans = height;
                break;
            }

            if(x-1>=0 && vis[x-1][y] == 0){
                vis[x-1][y] = 1;
                pq.push(make_pair(max(height, grid[x-1][y]), make_pair(x-1, y)));
            }

            if(x+1<rows && vis[x+1][y] == 0){
                vis[x+1][y] = 1;
                pq.push(make_pair(max(height, grid[x+1][y]), make_pair(x+1, y)));
            }

            if(y-1>=0 && vis[x][y-1] == 0){
                vis[x][y-1] = 1;
                pq.push(make_pair(max(height, grid[x][y-1]), make_pair(x, y-1)));
            }

            if(y+1<cols && vis[x][y+1] == 0){
                vis[x][y+1] = 1;
                pq.push(make_pair(max(height, grid[x][y+1]), make_pair(x, y+1)));
            }
        }

        return ans;
    }
};