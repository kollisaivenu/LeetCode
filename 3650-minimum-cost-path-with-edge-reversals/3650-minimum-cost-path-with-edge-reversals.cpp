class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>graph(n);

        for(int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0], 2*edges[i][2]));
        }

        vector<int>dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;

        pq.push(make_pair(0, 0));

        while(!pq.empty()) {
            pair<int, int>p = pq.top();
            int distance = p.first;
            int node = p.second;
            pq.pop();

            if(dist[node] < distance) {
                continue;
            }

            for(int i=0;i<graph[node].size();i++) {
                if(dist[node] + graph[node][i].second < dist[graph[node][i].first]) {
                    dist[graph[node][i].first] = dist[node] + graph[node][i].second;
                    pq.push(make_pair(dist[graph[node][i].first], graph[node][i].first));
                }
            }
        }

        if(dist[n-1] == INT_MAX) {
            return -1;
        }
        
        return dist[n-1];
    }
};