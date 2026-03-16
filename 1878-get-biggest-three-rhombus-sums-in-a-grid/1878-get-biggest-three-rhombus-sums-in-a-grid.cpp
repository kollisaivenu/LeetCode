class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int, vector<int>, greater<int>>pq;
        unordered_map<int, bool>saw;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid.size();j++) {
                for(int k=0;k<grid[0].size();k++) {
                    if(j-i >= 0 && j+i < grid.size() && k-i >= 0 && k+i < grid[0].size()) {
                        int sum = getSum(grid, j, k, i);
                        if(sum == 420) {
                            cout<<j<<"\n";
                            cout<<k<<"\n";
                            cout<<i<<"\n";
                        }
                        if(saw[sum] == false && pq.size() < 3) {
                            pq.push(sum);
                        } else {
                            if(saw[sum] == false && sum > pq.top()) {
                                pq.pop();
                                pq.push(sum);
                            }
                        }
                        saw[sum] = true;
                    }
                }
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }

    int getSum(vector<vector<int>>&grid, int x, int y, int size) {
        if(size == 0) {
            return grid[x][y];
        }
        int sum = 0;

        // top left

        int x1 = x;
        int y1 = y-size;
        int x2 = x-size;
        int y2 = y;

        while(x1 != x2 && y1 != y2) {
            sum += grid[x1][y1];
            x1 = x1-1;
            y1 = y1+1;
        }

        // top right

        x1 = x-size;
        y1 = y;
        x2 = x;
        y2 = y+size;

        while(x1 != x2 && y1 != y2) {
            sum += grid[x1][y1];
            x1 = x1+1;
            y1 = y1+1;
        }

        // bottom right

        x1 = x;
        y1 = y+size;
        x2 = x+size;
        y2 = y;

        while(x1 != x2 && y1 != y2) {
            sum += grid[x1][y1];
            x1 = x1+1;
            y1 = y1-1;
        }

        // bottom left

        x1 = x+size;
        y1 = y;
        x2 = x;
        y2 = y-size;

        while(x1 != x2 && y1 != y2) {
            sum += grid[x1][y1];
            x1 = x1-1;
            y1 = y1-1;
        }

        //sum = sum - (grid[x+size][y] + grid[x-size][y] + grid[x][y-size] + grid[x][y+size]);
        return sum;
    }
};