class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), cmp);
        int ans;
        if(edges.size() > 0){
            ans = edges[edges.size()-1][2];
        } else {
            return 0;
        }

        int low = 0, high = edges.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(getConnectedComponents(n, edges, mid) <= k){
                if(mid != 0){
                    ans = min(ans, edges[mid-1][2]);
                    high = mid-1;
                } else {
                    ans = 0;
                    break;
                }
            } else {
                low = mid+1;
            }
        }
        return ans;        
    }

    int getConnectedComponents(int n, vector<vector<int>>&edges, int indexToChuck){
        vector<int>parent(n, 0);
        vector<int>rank(n, 0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<indexToChuck;i++){
            un(edges[i][0], edges[i][1], parent, rank);
        }

        unordered_map<int, int>m;
        for(int i=0;i<n;i++){
            m[find(i, parent)] = 1;
        }

        return m.size();
        
    }

    int find(int node, vector<int>&parent){
        if(node == parent[node]){
            return node;
        }

        return find(parent[node], parent);
    }

    void un(int node1, int node2, vector<int>&parent, vector<int>&rank){
        int p1 = find(node1, parent);
        int p2 = find(node2, parent);

        if(p1 != p2){
            if(rank[p1] < rank[p2]){
                parent[p1] = p2;
            } else if(rank[p1] > rank[p2]){
                parent[p2] = p1;   
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
};