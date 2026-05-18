class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<pair<int, int>, int>>q;
        int rows = rooms.size();
        int cols = rooms[0].size();
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(rooms[i][j] == 0) {
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }

        while(!q.empty()) {
            pair<int, int>p = q.front().first;
            int dist = q.front().second;
            q.pop();
            int x = p.first;
            int y = p.second;
            
            if(x-1 >= 0 && rooms[x-1][y] > dist+1) {
                rooms[x-1][y] = dist+1;
                q.push(make_pair(make_pair(x-1, y), dist+1));
            }

            if(y-1 >= 0 && rooms[x][y-1] > dist+1) {
                rooms[x][y-1] = dist+1;
                q.push(make_pair(make_pair(x, y-1), dist+1));
            }

            if(x+1 < rows && rooms[x+1][y] > dist+1) {
                rooms[x+1][y] = dist+1;
                q.push(make_pair(make_pair(x+1, y), dist+1));
            }

            if(y+1 < cols && rooms[x][y+1] > dist+1) {
                rooms[x][y+1] = dist+1;
                q.push(make_pair(make_pair(x, y+1), dist+1));
            }
        }
    }
};