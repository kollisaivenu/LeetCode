class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int layers = min(rows/2, cols/2);

        for(int i_start=0,j_start=0,i_end=rows-1,j_end=cols-1,layer=1;layer<=layers;i_start++,j_start++,i_end--,j_end--,layer++) {
            int eff_rot = k%(2*(i_end-i_start) + 2*(j_end-j_start));
            for(int rot=1;rot<=eff_rot;rot++) {
                // cover left vertical lane;
                int temp = grid[i_start][j_start];

                for(int a=i_start+1;a<=i_end;a++) {
                    int sec_temp = grid[a][j_start];
                    grid[a][j_start] = temp;
                    temp = sec_temp;
                }

                // cover bottom horizontal lane;
                for(int a=j_start+1;a<=j_end;a++) {
                    int sec_temp = grid[i_end][a];
                    grid[i_end][a] = temp;
                    temp = sec_temp;
                }

                // cover right vertical lane;
                for(int a=i_end-1;a>=i_start;a--) {
                    int sec_temp = grid[a][j_end];
                    grid[a][j_end] = temp;
                    temp = sec_temp;
                }

                // cover top horizontal lane;
                for(int a=j_end-1;a>=j_start;a--) {
                    int sec_temp = grid[i_start][a];
                    grid[i_start][a] = temp;
                    temp = sec_temp;
                }
            }
        }

        return grid;   
    }
};