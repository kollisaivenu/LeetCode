class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int neg = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=col-1;j>=0;j--) {
                if(grid[i][j] < 0) {
                    neg++;
                } else {
                    break;
                }
            }
        }

        return neg;
    }
};