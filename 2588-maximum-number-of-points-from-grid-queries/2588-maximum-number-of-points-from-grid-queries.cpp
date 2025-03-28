class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<int>ans(queries.size());
        vector<pair<int, int>>qs;

        for(int i=0;i<queries.size();i++){
            qs.push_back(make_pair(queries[i], i));
        }
        sort(qs.begin(), qs.end());
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));
        vis[0][0] = true;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
        pq.push(make_pair(grid[0][0], make_pair(0, 0)));
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i=0; i<qs.size();i++){
            int queryValue = qs[i].first;
            int idx = qs[i].second;
            while(!pq.empty() && pq.top().first < queryValue){
                int gridValue = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                count++;

                for(int i=0;i<4;i++){
                    int nx = x + dirs[i][0], ny = y + dirs[i][1];

                    if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && vis[nx][ny] == false){
                        pq.push(make_pair(grid[nx][ny], make_pair(nx, ny)));
                        vis[nx][ny] = true;
                    }
                }
            }
            ans[idx] = count;
        }
        return ans;
    }
};