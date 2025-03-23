class Solution {
public:
    vector<vector<pair<int, int>>>graph;
    int countPaths(int n, vector<vector<int>>& roads) {
        graph.resize(n);

        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
            graph[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
        }

        return getNumberOfWays(0, n-1);
    }

    int getNumberOfWays(int src, int dst){
        vector<long long>time(graph.size(), LLONG_MAX);
        vector<int>noOfWays(graph.size(), 0);
        noOfWays[src] = 1;
        time[src] = 0;
        int MOD = 1000000007;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        pq.push(make_pair(0, src));

        while(!pq.empty()){
            pair<int, int>p = pq.top();
            pq.pop();
            int u = p.second;

            if(p.first > time[u]){
                continue;
            }

            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first;
                long long t = graph[u][i].second;
                if(time[u] + t < time[v]){
                    time[v] = time[u] + t;
                    pq.push(make_pair(time[v], v));
                    noOfWays[v] = noOfWays[u];
                } else if(time[u] + t == time[v]){
                    noOfWays[v] = (noOfWays[v] + noOfWays[u])%MOD;
                }
            }
        }
        return noOfWays[dst];

    }
};