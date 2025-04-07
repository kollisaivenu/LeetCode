class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, int>costs;
        vector<int>parent(n, 0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++){
            unionNode(parent, edges[i][0], edges[i][1]);
        }

        for(int i=0;i<edges.size();i++){
            int parentOfBothNodes = getParent(parent, edges[i][0]);
            if(costs.find(parentOfBothNodes) != costs.end()){
                costs[parentOfBothNodes] = costs[parentOfBothNodes] & edges[i][2];
            } else {
                costs[parentOfBothNodes] = edges[i][2];
            }
        }
        vector<int>ans;
        for(int i=0;i<query.size();i++){
            if(getParent(parent, query[i][0]) == getParent(parent, query[i][1])){
                ans.push_back(costs[getParent(parent, query[i][0])]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
        
    }

    int getParent(vector<int>&parent, int a){
        if(a != parent[a]){
            parent[a] = getParent(parent, parent[a]);
        }
        return parent[a];
    }

    void unionNode(vector<int>& parent, int a, int b){
        int parentOfA = getParent(parent, a);
        int parentOfB = getParent(parent, b);
        parent[parentOfA] = parentOfB;
    }
};