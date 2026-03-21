class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>gridCopy = grid;
        for(int i=x,j=x+k-1;i<j;i++,j--) {
            for(int l=y;l<y+k;l++) {
                int temp = gridCopy[i][l];
                gridCopy[i][l] = gridCopy[j][l];
                gridCopy[j][l] = temp;
            }
        }

        return gridCopy; 
    }
};