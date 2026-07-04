class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>graph(n);

        for(int i=0;i<roads.size();i++) {
            graph[roads[i][0]-1].push_back({roads[i][1]-1, roads[i][2]});
            graph[roads[i][1]-1].push_back({roads[i][0]-1, roads[i][2]});
        }

        int edge = INT_MAX;
        vector<bool>vis(n, false);
        vis[0] = true;
        dfs(graph, 0, vis);
        for(int i=0;i<roads.size();i++) {
            if(vis[roads[i][0]-1] == true && vis[roads[i][1]-1] == true) {
                edge = min(edge, roads[i][2]);
            }
        }
        return edge;
    }

    void dfs(vector<vector<pair<int, int>>> &graph, int node, vector<bool>&visited) {
        for(int i=0;i<graph[node].size();i++) {
            if(!visited[graph[node][i].first]) {
                visited[graph[node][i].first] = true;
                dfs(graph, graph[node][i].first, visited);
            }
        }
    }
};