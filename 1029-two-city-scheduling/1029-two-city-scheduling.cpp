class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, int>>pq;

        for(int i=0;i<costs.size();i++) {
            pq.push(make_pair(abs(costs[i][0]-costs[i][1]), i));
        }

        int a = 0, b = 0, ans = 0;

        while(a<costs.size()/2 && b<costs.size()/2) {
            pair<int, int>p = pq.top();
            pq.pop();

            if(costs[p.second][0] <= costs[p.second][1]) {
                ans += costs[p.second][0];
                a++;
            } else {
                ans += costs[p.second][1];
                b++;
            }
        }

        if(a < costs.size()/2) {
            while(!pq.empty()) {
                pair<int, int>p = pq.top();
                pq.pop();
                ans += costs[p.second][0];
            }
        }

        if(b < costs.size()/2) {
            while(!pq.empty()) {
                pair<int, int>p = pq.top();
                pq.pop();
                ans += costs[p.second][1];
            }
        }

        return ans;
        
    }
};