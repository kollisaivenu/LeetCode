class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        long long int sum = 0;
        int neg = 0;
        int minimum = INT_MAX;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                sum = sum + abs(matrix[i][j]);
                minimum = min(minimum, abs(matrix[i][j]));
                if(matrix[i][j] <= 0){
                    neg++;
                }
            }
        }
        if(neg%2 == 0){
            return sum;
        } else {
            return sum - 2*minimum;
        }
    }
};