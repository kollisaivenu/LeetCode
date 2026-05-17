class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>parent(n, 0);

        for(int i=0;i<n;i++) {
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++) {
            if(find(edges[i][0], parent) == find(edges[i][1], parent)) {
                return false;
            } else {
                un(edges[i][0], edges[i][1], parent);
            }
        }

        return edges.size() == n-1;
    }

    int find(int a, vector<int>&parent) {
        if(a == parent[a]) {
            return a;
        }
        parent[a] = find(parent[a], parent);
        return parent[a];
    }

    void un(int a, int b, vector<int>&parent) {
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);

        parent[parent_a] = parent_b;
    }
};