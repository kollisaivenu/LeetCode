class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool poss = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] != target[i][j]) {
                    poss = false;
                    break;
                }
            }
        }

        if(poss) {
            return true;
        }

        poss = true;
        for(int i=0,l=n-1;i<n,l>=0;i++,l--) {
            for(int j=0,m=0;j<n,m<n;j++,m++) {
                if(mat[i][j] != target[m][l]) {
                    poss = false;
                    break;
                }
            }
        }

        if(poss) {
            return true;
        }

        poss = true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] != target[n-i-1][n-j-1]) {
                    poss = false;
                    break;
                }
            }
        }

        if(poss) {
            return true;
        }

        poss = true;
        for(int i=0,l=0;i<n,l<n;i++,l++) {
            for(int j=0,m=n-1;j<n,m>=0;j++,m--) {
                if(mat[i][j] != target[m][l]) {
                    poss = false;
                    break;
                }
            }
        }

        if(poss) {
            return true;
        }

        return false;
    }
};