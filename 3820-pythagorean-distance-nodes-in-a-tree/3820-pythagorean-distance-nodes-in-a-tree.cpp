class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<long long>distX(n, 0);
        vector<long long>distY(n, 0);
        vector<long long>distZ(n, 0);

        vector<vector<int>>graph(n);

        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        findDist(graph, x, distX);
        findDist(graph, y, distY);
        findDist(graph, z, distZ);

        int ans = 0;
        vector<long long>dist(3, 0);
        for(int i=0;i<n;i++) {
            dist[0] = distX[i];
            dist[1] = distY[i];
            dist[2] = distZ[i];

            sort(dist.begin(), dist.end());

            if(dist[2]*dist[2] == dist[0]*dist[0] + dist[1]*dist[1]) {
                ans++;
            }
        }

        return ans;
    }

    

    void findDist(vector<vector<int>>&graph, int u, vector<long long>&dist) {
        queue<pair<int, int>>q;
        vector<bool>vis(graph.size() , false);
        vis[u] = true;
        q.push(make_pair(u, 0));

        while(!q.empty()) {
            pair<int, int>p = q.front();
            q.pop();
            int node = p.first;
            int dis = p.second;
            dist[node] = dis;
            //cout<<node<<"\n";
            for(int i=0;i<graph[node].size();i++) {
                if(vis[graph[node][i]] == false) {
                    q.push(make_pair(graph[node][i], dis+1));
                    vis[graph[node][i]] = true;
                }
            }
        }
    }
};