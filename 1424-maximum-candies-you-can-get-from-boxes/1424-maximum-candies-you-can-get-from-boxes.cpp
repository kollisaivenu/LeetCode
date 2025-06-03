class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalCandies = 0;
        int opened = 0;
        vector<vector<int>>graph(status.size());
        vector<int>chocolateAdded(status.size(), 0);
        vector<int>vis(status.size(), 0);
        queue<int>q;
        
        for(int i=0;i<status.size();i++){
            for(int j=0;j<containedBoxes[i].size();j++){
                graph[i].push_back(containedBoxes[i][j]);
            }
        }

        for(int i=0;i<initialBoxes.size();i++){
            q.push(initialBoxes[i]);
        }

        while(!q.empty()){
            int box = q.front();
            q.pop();

            if(vis[box] == 0){
                vis[box] = 1;
                if(status[box] == 1){
                    opened++;
                    totalCandies += candies[box];
                    chocolateAdded[box] = 1;

                    for(int i=0;i<keys[box].size();i++){
                        status[keys[box][i]] = 1;
                        if(vis[keys[box][i]] == 1 && chocolateAdded[keys[box][i]] == 0){
                            q.push(keys[box][i]);
                            vis[keys[box][i]] = 0;
                        } 
                    }

                    for(int i=0;i<graph[box].size();i++){
                        if(vis[graph[box][i]] == 0) q.push(graph[box][i]);
                    }
                }
            }
        }

        return totalCandies;
    }
};