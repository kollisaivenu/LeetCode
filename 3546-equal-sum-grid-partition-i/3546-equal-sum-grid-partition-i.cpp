class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int64_t sum = 0;
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                sum += grid[i][j];  
            }
        }
        int64_t currSum = 0;
        for(int i=0;i<rows-1;i++) {
            for(int j=0;j<cols;j++) {
                currSum += grid[i][j];
            }

            if(currSum == (sum - currSum)) {
                return true;
            }
        }

        currSum = 0;
        for(int i=0;i<cols-1;i++) {
            for(int j=0;j<rows;j++) {
                currSum += grid[j][i];
            }

            if(currSum == (sum - currSum)) {
                return true;
            }
        }

        return false;
    }
};