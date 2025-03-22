class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<vector<bool>>edgePresent(n, vector<bool>(n, false));
        vector<int>nodeVisited(n, false);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

            edgePresent[edges[i][0]][edges[i][1]] = true;
            edgePresent[edges[i][1]][edges[i][0]] = true;
        }
        int noOfCompleteComponents = 0;
        for(int i=0;i<n;i++){
            vector<int>nodesOfComponent;
            bool edgeNotPresent = false;
            if(!nodeVisited[i]){
                dfs(i, nodeVisited, nodesOfComponent, graph);

                for(int i=0;i<nodesOfComponent.size();i++){
                    for(int j=i+1;j<nodesOfComponent.size();j++){
                        if(!edgePresent[nodesOfComponent[i]][nodesOfComponent[j]]){
                            edgeNotPresent = true;
                            break;
                        }

                        if(edgeNotPresent){
                            break;
                        }
                    }
                }

                if(!edgeNotPresent){
                    noOfCompleteComponents++;
                }
            }
        }
        return noOfCompleteComponents;
    }

    void dfs(int node, vector<int>&vis, vector<int>& nodesOfComponent, vector<vector<int>>& graph){
        nodesOfComponent.push_back(node);
        vis[node] = true;

        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                dfs(graph[node][i], vis, nodesOfComponent, graph);
            }
        }
    }
};