class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int, int>, bool>obs;
        
        for(int i=0;i<obstacles.size();i++) {
            pair<int, int>p = make_pair(obstacles[i][0], obstacles[i][1]);
            obs[p] = true;
        }

        // 0 is north
        // 1 is south
        // 2 is west
        // 3 is east
        int move = 0;
        int x = 0, y = 0;
        int farthest = 0;
        for(int i=0;i<commands.size();i++) {
            if(commands[i] == -2) {
                if(move == 0) {
                    move = 2;
                } else if(move == 1) {
                    move = 3;
                } else if(move == 2) {
                    move = 1;
                } else {
                    move = 0;
                }
            } else if(commands[i] == -1) {
                if(move == 0) {
                    move = 3;
                } else if(move == 1) {
                    move = 2;
                } else if(move == 2) {
                    move = 0;
                } else {
                    move = 1;
                }
            } else {
                for(int j=1;j<=commands[i];j++) {
                    int new_x = x;
                    int new_y = y;
                    
                    if(move == 0) {
                        new_y += 1;
                    } else if(move == 1) {
                        new_y -= 1;
                    } else if(move == 2) {
                        new_x -= 1;
                    } else {
                        new_x += 1;
                    }

                    if(obs[make_pair(new_x, new_y)] == true) {
                        break;
                    } else {
                        x = new_x;
                        y = new_y;
                    }
                    farthest = max(farthest, abs(x)*abs(x) + abs(y)*abs(y));
                }
            }
        }

        return farthest;
    }
};