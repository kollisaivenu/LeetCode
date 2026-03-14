class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int>cza(rows, 0);
        vector<int>c(rows, 0);
        for(int i=0;i<rows;i++) {
            if(grid[i][cols-1] == 0){
                int j=cols-1;
                int count = 0;
                while(j >= 0 && grid[i][j] == 0){
                    j--;
                    count++;
                }
                cza[i] = count;
            }
        }
    
        int swaps = 0;
        vector<bool>inplace(rows, false);
        for(int i=0;i<rows;i++) {
            if(cza[i] < cols-i-1) {
                for(int j=i+1;j<rows;j++) {
                    if(cza[j] >= cols-i-1) {
                        inplace[i] = true;
                        int k=j;
                        while(k != i) {
                            int temp = cza[k];
                            cza[k] = cza[k-1];
                            cza[k-1] = temp;
                            swaps++;
                            k--;
                        }
                        break;
                    }
                }
            } else {
                inplace[i] = true;
            }

            if(inplace[i] == false) {
                return -1;
            }
        }

        return swaps;
    }
};