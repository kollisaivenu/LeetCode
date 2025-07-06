class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        map<int, priority_queue<int, vector<int>, greater<int>>>smallest;
        vector<int>isActive(c, 1);
        vector<int>parent(c);
        vector<int>rank(c, 0);
        vector<int>ans;
        for(int i=0;i<c;i++){
            parent[i] = i;
        }

        for(int i=0;i<connections.size();i++){
            un(parent, rank, connections[i][0]-1, connections[i][1]-1);
        }

        for(int i=0;i<c;i++){
            smallest[find(parent, i)].push(i);
        }
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][0] == 2){

                isActive[queries[i][1]-1] = 0;
            } else {
                if(isActive[queries[i][1]-1] == 1){
                    ans.push_back(queries[i][1]);
                } else {
                    int par = find(parent, queries[i][1]-1);

                    while(!smallest[par].empty() && isActive[smallest[par].top()] == false){
                        smallest[par].pop();
                    }
                    
                    if(smallest[par].empty()){
                        ans.push_back(-1);
                    } else {
                        ans.push_back(smallest[par].top()+1);
                    }
                }
                
            }
        }

        return ans;
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