class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> cells;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>>visAtlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>>visPacific(rows, vector<bool>(cols, false));

        for(int i=0;i<rows;i++){
            dfs(i, 0, heights, visPacific);
        }

        for(int j=0;j<cols;j++){
            dfs(0, j, heights, visPacific);
        }

        for(int i=0;i<rows;i++){
            dfs(i, cols-1, heights, visAtlantic);
        }

        for(int j=0;j<cols;j++){
            dfs(rows-1, j, heights, visAtlantic);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                if(visAtlantic[i][j] && visPacific[i][j]){
                    vector<int> cell;
                    cell.push_back(i);
                    cell.push_back(j);
                    cells.push_back(cell);
                }
            }
        }
        return cells;
        
    }



    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>&vis){
        vis[i][j] = true;
        int rows = heights.size();
        int cols = heights[0].size();

        if(i+1<rows && vis[i+1][j] == false && heights[i+1][j] >= heights[i][j]){
            dfs(i+1, j, heights, vis);
        }

        if(i-1>=0 && vis[i-1][j] == false && heights[i-1][j] >= heights[i][j]){
            dfs(i-1, j, heights, vis);
        }

        if(j+1<cols && vis[i][j+1] == false && heights[i][j+1] >= heights[i][j]){
            dfs(i, j+1, heights, vis);
        }

        if(j-1>=0 && vis[i][j-1] == false && heights[i][j-1] >= heights[i][j]){
            dfs(i, j-1, heights, vis);
        }
    }
};
