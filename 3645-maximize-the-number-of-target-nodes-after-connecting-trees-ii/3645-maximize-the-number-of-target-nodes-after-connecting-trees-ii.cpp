class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>>graph1(edges1.size()+1);
        vector<vector<int>>graph2(edges2.size()+1);

        for(int i=0;i<edges1.size();i++){
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }

        for(int i=0;i<edges2.size();i++){
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }

        vector<int>color1 = bfs(graph1);
        vector<int>color2 = bfs(graph2);
        int white1 = 0, black1 = 0, white2 = 0, black2 = 0;

        for(int i=0;i<color1.size();i++){
            if(color1[i] == 0){
                white1++;
            } else {
                black1++;
            }
        }

        for(int i=0;i<color2.size();i++){
            if(color2[i] == 0){
                white2++;
            } else {
                black2++;
            }
        }
        vector<int>ans(color1.size(), 0);
        for(int i=0;i<color1.size();i++){
            if(color1[i] == 0){
                ans[i] = white1 + max(black2, white2);
            } else {
                ans[i] = black1 + max(black2, white2);
            }
        }

        return ans;
        
    }

    vector<int> bfs(vector<vector<int>>&graph){
        vector<int>vis(graph.size(), 0);
        vector<int>color(graph.size(), 0);
        int level = 0;
        queue<int>q;
        q.push(0);

        while(!q.empty()){
            q.push(-1);

            while(q.front() != -1){
                
                int node = q.front();
                q.pop();

                if(vis[node] == 0){
                    vis[node] = 1;
                    if(level%2 == 0){
                        color[node] = 0;
                    } else {
                        color[node] = 1;
                    }

                    for(int j=0;j<graph[node].size();j++){
                        q.push(graph[node][j]);
                    }
                }   
            }
            q.pop();
            level++;
        }
        return color;
    }
};