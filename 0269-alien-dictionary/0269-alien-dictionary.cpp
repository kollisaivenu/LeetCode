class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, vector<int>>graph;
        unordered_map<int, int>indeg;
        for(string word: words) {
            for(char c: word) {
                graph[c-'a'] = vector<int>();
                indeg[c-'a'] = 0;
            }
        }

        for(int i=1;i<words.size();i++) {
            string word1 = words[i-1];
            string word2 = words[i];

            if(word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }
        }

        for(int i=1;i<words.size();i++) {
            for(int j=0;j<min(words[i].length(), words[i-1].length());j++) {
                if(words[i][j] != words[i-1][j]) {
                    graph[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                    break;
                }
            }
        }

        queue<int>q;
        for(auto edges: graph) {
            for(int edge: edges.second) {
                indeg[edge]++;
            }
        }

        for(auto items: indeg) {
            if(items.second == 0) {
                q.push(items.first);
            }
        }
        
        vector<int>topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int i=0;i<graph[node].size();i++) {
                indeg[graph[node][i]]--;

                if(indeg[graph[node][i]] == 0) {
                    q.push(graph[node][i]);
                }
            }
        }

        if(topo.size() != graph.size()) {
            cout<<topo.size()<<"\n";
            cout<<graph.size()<<"\n";
            cout<<"came here\n";
            return "";
        }
        string str = "";
        for(int i: topo) {
            str += (char)(i+'a');
        }

        return str;
    }
};