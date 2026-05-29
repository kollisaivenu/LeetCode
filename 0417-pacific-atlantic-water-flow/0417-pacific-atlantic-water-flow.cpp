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
            dfs(0, i, heights, pacific);
        }
        
        for(int i=0;i<rows;i++) {
            dfs(i, 0, heights, pacific);
        }

        // atlantic
        for(int i=0;i<cols;i++) {
            dfs(rows-1, i, heights, atlantic);
        }
        
        for(int i=0;i<rows;i++) {
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
        ocean[x][y] = true;
        int rows = heights.size();
        int cols = heights[0].size();

        if(x-1 >= 0 && heights[x-1][y] >= heights[x][y] && ocean[x-1][y] == false) {
            dfs(x-1, y, heights, ocean);
        }

        if(x+1 < rows && heights[x+1][y] >= heights[x][y] && ocean[x+1][y] == false) {
            dfs(x+1, y, heights, ocean);
        }

        if(y-1 >= 0 && heights[x][y-1] >= heights[x][y] && ocean[x][y-1] == false) {
            dfs(x, y-1, heights, ocean);
        }

        if(y+1 < cols && heights[x][y+1] >= heights[x][y] && ocean[x][y+1] == false) {
            dfs(x, y+1, heights, ocean);
        }
        
    }
};