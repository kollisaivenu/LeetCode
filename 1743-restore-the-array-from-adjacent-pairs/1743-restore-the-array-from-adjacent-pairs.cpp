class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int>freq;
        unordered_map<int, vector<int>>next;
        for(int i=0;i<adjacentPairs.size();i++){
            next[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            next[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        int start = INT_MAX;

        for(auto itr=next.begin(); itr != next.end();itr++) {
            if(itr->second.size() == 1) start = itr->first;
        }
        vector<int>ans(adjacentPairs.size()+1, 0);
        ans[0] = start;

        for(int i=0;i<adjacentPairs.size();i++) {
            vector<int>ps = next[ans[i]];

            if(ps.size() == 1) {
                ans[i+1] = ps[0];
            } else {
                if(ans[i-1] == ps[0]) {
                    ans[i+1] = ps[1];
                } else {
                    ans[i+1] = ps[0];
                }
            }
        }
        return ans;
        
    }
};