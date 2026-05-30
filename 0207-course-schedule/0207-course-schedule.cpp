class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses, vector<int>());

        for(int i=0;i<prerequisites.size();i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int>indeg(numCourses, 0);

        for(int i=0;i<numCourses;i++) {
            for(int j=0;j<graph[i].size();j++) {
                indeg[graph[i][j]]++;
            }
        }
        queue<int>q;
        int coveredSubs = 0;
        for(int i=0;i<numCourses;i++) {
            if(indeg[i] == 0) {
                q.push(i);
                coveredSubs++;
            }
        }

        while(!q.empty()) {
            int sub = q.front();
            q.pop();

            for(int i=0;i<graph[sub].size();i++) {
                indeg[graph[sub][i]]--;

                if(indeg[graph[sub][i]] == 0) {
                    q.push(graph[sub][i]);
                    coveredSubs++;
                }
            }
        }

        return coveredSubs == numCourses;

    }
};