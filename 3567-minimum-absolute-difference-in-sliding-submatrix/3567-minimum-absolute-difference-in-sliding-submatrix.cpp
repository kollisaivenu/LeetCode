class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>>subMatrix(k, vector<int>(k, 0));
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>ans(rows-k+1, vector<int>(cols-k+1, 0));
        
        for(int i=0;i<rows-k+1;i++){
            for(int j=0;j<cols-k+1;j++){
                map<int, bool>isPresent;
                priority_queue<int>pq;
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++){
                        if(!isPresent[grid[i+x][j+y]]){
                            pq.push(grid[i+x][j+y]);
                            isPresent[grid[i+x][j+y]] = true;
                        }
                    }
                }


                int minAbsDifference = INT_MAX;
                if(pq.size() == 1){
                    minAbsDifference = 0;
                }
                while(pq.size()>1){
                    int element = pq.top();
                    pq.pop();

                    minAbsDifference = min(minAbsDifference, element - pq.top());
                }
                ans[i][j] = minAbsDifference;
            }
        }

        return ans;
    }
};