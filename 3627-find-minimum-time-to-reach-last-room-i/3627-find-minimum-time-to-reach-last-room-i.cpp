class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();
        int ans = 0;
        vector<vector<int>>vis(rows, vector<int>(cols, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push(make_pair(0, make_pair(0, 0)));
        vis[0][0] = 1;

        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == rows-1 && y == cols-1){
                ans = time;
                break;
            }
            vector<int>changeDimX = {-1, 0, 1, 0};
            vector<int>changeDimY = {0, 1, 0, -1};

            for(int i=0;i<4;i++){
                int newX = x + changeDimX[i];
                int newY = y + changeDimY[i];
                if(isValid(newX, newY, vis)){
                    vis[newX][newY] = 1;
                    pq.push(make_pair(max(moveTime[newX][newY], time)+1, make_pair(newX, newY)));
                }
            }

        }
        return ans;
    }

    bool isValid(int x, int y, vector<vector<int>>&vis){
        int rows = vis.size();
        int cols = vis[0].size();

        return (x >= 0 && x < rows && y >= 0 && y < cols && vis[x][y] == 0);
    }
};