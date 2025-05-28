class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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

        int maxInOtherTree = 0;
        for(int i=0;i<=edges2.size();i++){
            maxInOtherTree = max(bfs(i, graph2, k-1), maxInOtherTree);
        }
        
        vector<int>target1(edges1.size()+1, 0);
        for(int i=0;i<=edges1.size();i++){
            target1[i] = bfs(i, graph1, k) + maxInOtherTree;
        }

        return target1;
        
    }

    int bfs(int i, vector<vector<int>>&graph, int k){
        if(k<0){
            return 0;
        }
        vector<int>vis(graph.size(), 0);
        int ans = 0;
        int level = 0;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            q.push(-1);

            while(q.front() != -1){
                
                int node = q.front();
                q.pop();

                if(vis[node] == 0){
                    vis[node] = 1;
                    ans++;

                    for(int j=0;j<graph[node].size();j++){
                        q.push(graph[node][j]);
                    }
                }   
            }
            q.pop();
            level++;

            if(level > k){
                break;
            }
        }
        return ans;
    }
};