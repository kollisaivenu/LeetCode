class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1, 0);
        for(int i=0;i<=edges.size();i++) {
            parent[i] = i;
        }

        vector<int>ans;
        for(auto edge: edges) {
            if(find(edge[0], parent) == find(edge[1], parent)) {
                ans = edge;
            } else {
                un(edge[0], edge[1], parent);
            }
        }

        return ans;
    }

    void un(int a, int b, vector<int>&parent) {
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);

        parent[parent_a] = parent_b;
    }

    int find(int a, vector<int>&parent) {
        if(a == parent[a]) {
            return a;
        }

        parent[a] = find(parent[a], parent);
        return parent[a];
    }
};