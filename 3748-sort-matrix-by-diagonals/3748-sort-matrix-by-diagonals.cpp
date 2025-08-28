class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            vector<int>diag;
            for(int j=i,k=0;j<n && k<n;j++,k++){
                diag.push_back(grid[j][k]);
            }

            sort(diag.begin(), diag.end());
            reverse(diag.begin(), diag.end());

            for(int j=i,k=0;j<n && k<n;j++,k++){
                ans[j][k] = diag[k];
            }
        }

        for(int i=1;i<n;i++){
            vector<int>diag;
            for(int j=i,k=0;j<n && k<n;j++,k++){
                diag.push_back(grid[k][j]);
            }
            sort(diag.begin(), diag.end());
            for(int j=i,k=0;j<n && k<n;j++,k++){
                ans[k][j] = diag[k];
            }
        }

        return ans;
    }
};