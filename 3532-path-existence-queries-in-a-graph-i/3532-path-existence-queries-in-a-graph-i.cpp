class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>parent(n, 0);

        for(int i=0;i<n;i++) {
            parent[i] = i;
        }

        for(int i=1;i<n;i++) {
            if(nums[i] - nums[i-1] <= maxDiff) {
                un(i-1, i, parent);
            }
        }

        vector<bool>ans;

        for(int i=0;i<queries.size();i++) {
            if(find(queries[i][0], parent) == find(queries[i][1], parent)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }

    int find(int node, vector<int>&parent) {
        if(parent[node] == node) {
            return node;
        }
        parent[node] = find(parent[node], parent);
        return parent[node];
    }

    void un(int node1, int node2, vector<int>&parent) {
        int p1 = find(node1, parent);
        int p2 = find(node2, parent);

        parent[p1] = p2;
    }
};