class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>>x,y;

        for(int i=0;i<buildings.size();i++){
            if(x.count(buildings[i][0]) == 0) {
                x[buildings[i][0]] = {INT_MAX, INT_MIN};
            }

            x[buildings[i][0]][0] = min(x[buildings[i][0]][0], buildings[i][1]);
            x[buildings[i][0]][1] = max(x[buildings[i][0]][1], buildings[i][1]);

            if(y.count(buildings[i][1]) == 0) {
                y[buildings[i][1]] = {INT_MAX, INT_MIN};
            }

            y[buildings[i][1]][0] = min(y[buildings[i][1]][0], buildings[i][0]);
            y[buildings[i][1]][1] = max(y[buildings[i][1]][1], buildings[i][0]);
            
        }
        int ans = 0;
        for(int i=0;i<buildings.size();i++){
            int x_coor = buildings[i][0];
            int y_coor = buildings[i][1];

            if(x[x_coor][0] < y_coor && x[x_coor][1] > y_coor && y[y_coor][0] < x_coor && y[y_coor][1] > x_coor) {
                ans++;
            }
        }
        
        return ans;
        
    }
};