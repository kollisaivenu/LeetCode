class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>>graph(edges.size());

        for(int i=0;i<edges.size();i++){
            if(edges[i] != -1) {
                graph[i].push_back(edges[i]);
            }
        }
        vector<int>level1 = bfs(graph, node1);
        vector<int>level2 = bfs(graph, node2);
        int ans = -1;
        int maxDist = INT_MAX;
        
        for(int i=0;i<edges.size();i++){
            if(level1[i] != INT_MAX && level2[i] != INT_MAX && max(level1[i], level2[i]) < maxDist){
                ans = i;
                maxDist = max(level1[i], level2[i]);
            }
        }
        return ans; 
    }

    vector<int>bfs(vector<vector<int>>&graph, int node){
        queue<int>q;
        vector<int>node2level(graph.size(), INT_MAX);
        vector<int>vis(graph.size(), 0);
        q.push(node);
        int level = 0;

        while(!q.empty()){
            q.push(-1);

            while(q.front() != -1){
                int n = q.front();
                q.pop();

                if(vis[n] == 0){
                    vis[n] = 1;
                    node2level[n] = level;

                    for(int i=0;i<graph[n].size();i++){
                        q.push(graph[n][i]);
                    }
                }
                
            }
            q.pop();
            level++;
        }

        return node2level;
    }

};