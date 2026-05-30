class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int, int>>q;
        vector<vector<pair<int, int>>>graph(n+1);

        for(int i=0;i<times.size();i++) {
            graph[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push(make_pair(0, k));
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if(dist[u] < dis) {
                continue;
            }
            
            for(int i=0;i<graph[u].size();i++) {
                int v = graph[u][i].first;
                int w = graph[u][i].second;

                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
         int ans = INT_MIN;

         for(int i=1;i<=n;i++) {
            ans = max(ans, dist[i]);
         }

         if(ans == INT_MAX) {
            return -1;
         }

         return ans;
    }
};