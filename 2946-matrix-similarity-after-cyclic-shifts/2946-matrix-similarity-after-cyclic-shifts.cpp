class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>matCopy = mat;
        int row = mat.size();
        int col = mat[0].size();
        for(int i=0;i<k;i++) {
            for(int r=0;r<row;r++) {
                if(r%2 == 0) {
                    int temp = matCopy[r][0];
                    for(int c=col-1;c>=0;c--) {
                        int ltemp = matCopy[r][c];
                        matCopy[r][c] = temp;
                        temp = ltemp;         
                    }
                } else {
                    int temp = matCopy[r][col-1];
                    for(int c=0;c<col;c++) {
                        int ltemp = matCopy[r][c];
                        matCopy[r][c] = temp;
                        temp = ltemp;         
                    }
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                if(matCopy[i][j] != mat[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};