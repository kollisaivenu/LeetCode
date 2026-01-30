class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(26, vector<long long>(26, LLONG_MAX));
        for(int i=0;i<26;i++){
            dist[i][i] = 0;
        }
        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dist[j][i] != LLONG_MAX && dist[i][k] != LLONG_MAX && dist[j][k] > dist[j][i] + dist[i][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(dist[i][j] == LLONG_MAX){
                    dist[i][j] = -1;
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.length();i++){
            if(source[i] != target[i]){
                if(dist[source[i]-'a'][target[i]-'a'] == -1){
                    return -1;
                } else {
                    ans += dist[source[i]-'a'][target[i]-'a'];
                }
            }
        }

        return ans;        
    }
};