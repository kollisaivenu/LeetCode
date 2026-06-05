class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>paths;
        vector<int>currentPath;
        currentPath.push_back(0);
        getPaths(graph, paths, currentPath, 0);
        return paths;
    }

    void getPaths(vector<vector<int>>&graph, vector<vector<int>>&path, vector<int>&currentPath, int node) {
        int n = graph.size()-1;

        if(node == n) {
            path.push_back(currentPath);
            return;
        }

        for(int i=0;i<graph[node].size();i++) {
            currentPath.push_back(graph[node][i]);
            getPaths(graph, path, currentPath, graph[node][i]);
            currentPath.pop_back();
        }
    }

};