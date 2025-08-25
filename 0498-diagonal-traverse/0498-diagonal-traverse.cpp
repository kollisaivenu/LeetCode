class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rev = false;

        int rows = mat.size();
        int cols = mat[0].size();
        vector<int>ans;
        for(int i=0;i<rows;i++){
            int k=0;
            vector<int>subans;
            for(int j=i;j>=0 && k<cols;j--,k++){
                subans.push_back(mat[j][k]);
            }

            if(i%2 == 1){
                reverse(subans.begin(), subans.end());
            }

            ans.insert(ans.end(), subans.begin(), subans.end());
        }

        for(int i=1;i<cols;i++){
            int k=rows-1;
            vector<int>subans;
            for(int j=i;j<cols && k>=0;j++,k--){
                subans.push_back(mat[k][j]);
            }

            if(i%2 == 1 && rows%2 == 1 || i%2 == 0 && rows%2 == 0){
                reverse(subans.begin(), subans.end());
            }

            ans.insert(ans.end(), subans.begin(), subans.end());
        }

        return ans;
        
        
    }
};