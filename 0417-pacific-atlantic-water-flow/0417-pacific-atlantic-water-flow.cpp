class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>>pacific(rows, vector<bool>(cols, false));
        vector<vector<int>>ans;
        
        // pacific 
        for(int i=0;i<cols;i++) {
            pacific[0][i] = true;
            dfs(0, i, heights, pacific);
        }
        
        for(int i=0;i<rows;i++) {
            pacific[i][0] = true;
            dfs(i, 0, heights, pacific);
        }

        // atlantic
        for(int i=0;i<cols;i++) {
            atlantic[rows-1][i] = true;
            dfs(rows-1, i, heights, atlantic);
        }
        
        for(int i=0;i<rows;i++) {
            atlantic[i][cols-1] = true;
            dfs(i, cols-1, heights, atlantic);
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(atlantic[i][j] && pacific[i][j]) {
                    vector<int>xy;
                    xy.push_back(i);
                    xy.push_back(j);
                    ans.push_back(xy);
                }
            }
        }

        return ans;
    }

    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>&ocean) {
        int rows = heights.size();
        int cols = heights[0].size();

        if(x-1 >= 0 && heights[x-1][y] >= heights[x][y] && ocean[x-1][y] == false) {
            ocean[x-1][y] = true;
            dfs(x-1, y, heights, ocean);
        }

        if(x+1 < rows && heights[x+1][y] >= heights[x][y] && ocean[x+1][y] == false) {
            ocean[x+1][y] = true;
            dfs(x+1, y, heights, ocean);
        }

        if(y-1 >= 0 && heights[x][y-1] >= heights[x][y] && ocean[x][y-1] == false) {
            ocean[x][y-1] = true;
            dfs(x, y-1, heights, ocean);
        }

        if(y+1 < cols && heights[x][y+1] >= heights[x][y] && ocean[x][y+1] == false) {
            ocean[x][y+1] = true;
            dfs(x, y+1, heights, ocean);
        }
        
    }
};