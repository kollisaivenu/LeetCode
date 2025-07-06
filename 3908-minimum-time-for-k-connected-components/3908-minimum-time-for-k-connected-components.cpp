class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int maxTime = 0;
        for(int i=0;i<edges.size();i++){
            maxTime = max(maxTime, edges[i][2]);
        }

        int low = 0, high = maxTime;
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isValid(mid, n, k, edges)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    bool isValid(int time, int n, int k, vector<vector<int>>& edges){
        vector<int>parent(n);
        vector<int>rank(n, 0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++){
            if(edges[i][2] > time){
                un(parent, rank, edges[i][0], edges[i][1]);
            }
        }

        unordered_set<int>uniqueParents;

        for(int i=0;i<n;i++){
            uniqueParents.insert(find(parent, i));
        }

        if(uniqueParents.size() >= k){
            return true;
        }

        return false;
    }

    int find(vector<int>&parent, int child){
        if(parent[child] == child){
            return child;
        }

        return find(parent, parent[child]);
    }

    void un(vector<int>&parent, vector<int>&rank, int child1, int child2){
        int parent1 = find(parent, child1);
        int parent2 = find(parent, child2);

        if(rank[parent1] < rank[parent2]){
            parent[parent1] = parent2;
        } else if(rank[parent2] < rank[parent1]){
            parent[parent2] = parent1;
        } else {
            parent[parent1] = parent2;
            rank[parent2]++;
        }
    }
};