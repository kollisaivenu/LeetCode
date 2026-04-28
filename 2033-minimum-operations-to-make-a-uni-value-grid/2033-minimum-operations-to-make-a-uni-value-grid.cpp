class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int remainder;
        vector<int>numbers;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i == 0 && j == 0){
                    remainder = grid[i][j]%x;
                } else if(remainder != grid[i][j]%x){
                    return -1;
                }
                numbers.push_back(grid[i][j]);
            }
        }
        sort(numbers.begin(), numbers.end());

        int totalSum = 0;

        for(int i=0;i<numbers.size();i++){
            totalSum += numbers[i];
        }
        int currSum = 0;
        int minNumberOfMoves = INT_MAX;
        for(int i=0;i<numbers.size();i++){
            totalSum -= numbers[i];
            int numberOfMoves = ((i-0)*numbers[i] - currSum)/x + (totalSum - (numbers.size() - 1 - i)*numbers[i])/x;
            currSum += numbers[i];
            minNumberOfMoves = min(numberOfMoves, minNumberOfMoves);
        }
        return minNumberOfMoves;

        
    }
};