class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<long long>>maxProduct(row, vector<long long>(col, LLONG_MIN));
        vector<vector<long long>>minProduct(row, vector<long long>(col, LLONG_MAX));
        long long ans = getMaxProduct(grid, 0, 0, row-1, col-1, maxProduct, minProduct);
        
        if(ans < 0) {
            return -1;
        }

        return ans%1000000007;
    }

    long long getMaxProduct(vector<vector<int>>&grid, int startX, int startY, int endX, int endY, vector<vector<long long>>&maxProduct, vector<vector<long long>>&minProduct) {
        if(startX == endX && startY == endY) {
            maxProduct[startX][startY] = grid[startX][startY];
            return grid[startX][startY];
        }

        if(maxProduct[startX][startY] != LLONG_MIN) {
            return maxProduct[startX][startY];
        }
        
        long long tempMaxProduct = LLONG_MIN;
        if(startX+1 <= endX && startY <= endY) {
            if(grid[startX][startY] > 0) {
                tempMaxProduct = max(tempMaxProduct, grid[startX][startY]*getMaxProduct(grid, startX+1, startY, endX, endY, maxProduct, minProduct));
            } else {
                tempMaxProduct = max(tempMaxProduct, grid[startX][startY]*getMinProduct(grid, startX+1, startY, endX, endY, maxProduct, minProduct));
            }
            
        }

        if(startX <= endX && startY+1 <= endY) {
            if(grid[startX][startY] > 0) {
                tempMaxProduct = max(tempMaxProduct, grid[startX][startY]*getMaxProduct(grid, startX, startY+1, endX, endY, maxProduct, minProduct));
            } else {
                tempMaxProduct = max(tempMaxProduct, grid[startX][startY]*getMinProduct(grid, startX, startY+1, endX, endY, maxProduct, minProduct));   
            }
            
        }
        maxProduct[startX][startY] = tempMaxProduct;
        return maxProduct[startX][startY];
    }

    long long getMinProduct(vector<vector<int>>&grid, int startX, int startY, int endX, int endY, vector<vector<long long>>&maxProduct, vector<vector<long long>>&minProduct) {
        if(startX == endX && startY == endY) {
            return grid[startX][startY];
        }

        if(minProduct[startX][startY] != LLONG_MAX) {
            return minProduct[startX][startY];
        }
        long long tempMinProduct = LLONG_MAX;
        if(startX+1 <= endX && startY <= endY) {
            if(grid[startX][startY] > 0) {
                tempMinProduct = min(tempMinProduct, grid[startX][startY]*getMinProduct(grid, startX+1, startY, endX, endY, maxProduct, minProduct));
            } else {
                tempMinProduct = min(tempMinProduct, grid[startX][startY]*getMaxProduct(grid, startX+1, startY, endX, endY, maxProduct, minProduct));
            }
        }

        if(startX <= endX && startY+1 <= endY) {
            if(grid[startX][startY] > 0) {
                tempMinProduct = min(tempMinProduct, grid[startX][startY]*getMinProduct(grid, startX, startY+1, endX, endY, maxProduct, minProduct));
            } else {
                tempMinProduct = min(tempMinProduct, grid[startX][startY]*getMaxProduct(grid, startX, startY+1, endX, endY, maxProduct, minProduct));   
            }
        }
        minProduct[startX][startY] = tempMinProduct;
        return minProduct[startX][startY];
    }
};