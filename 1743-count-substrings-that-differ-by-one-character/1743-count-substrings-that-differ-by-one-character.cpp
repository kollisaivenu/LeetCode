class Solution {
public:
    int countSubstrings(string s, string t) {
        vector<vector<int>>vis(s.length(), vector<int>(t.length(), 0));
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, 0));
        int ans = 0;
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                if(s[i] != t[j]){
                    int left_subarrays = 0;
                    int go_left_i = i-1;
                    int go_left_j = j-1;

                    while(go_left_i >=0 && go_left_j >= 0 && s[go_left_i] == t[go_left_j]){
                        left_subarrays++;
                        go_left_i--;
                        go_left_j--;
                    }

                    int right_subarrays = 0;
                    int go_right_i = i+1;
                    int go_right_j = j+1;

                    while(go_right_i < s.length() && go_right_j < t.length() && s[go_right_i] == t[go_right_j]){
                        right_subarrays++;
                        go_right_i++;
                        go_right_j++;
                    }
                    dp[i][j] += (1 + left_subarrays)*(1 + right_subarrays);
                }
                ans += dp[i][j];

            }
        }
        return ans;
        
    }
    int recur(string s, string t, int i, int j, vector<vector<int>>&vis){
        if(i >= s.length() || j >= t.length()){
            return 0;
        }
        int ans = 0;
        if(s[i] != t[j] && vis[i][j] == 0){
            vis[i][j] = 1;
            int left_subarrays = 0;
            int go_left_i = i-1;
            int go_left_j = j-1;

            while(go_left_i >=0 && go_left_j >= 0 && s[go_left_i] == t[go_left_j]){
                left_subarrays++;
                go_left_i--;
                go_left_j--;
            }

            int right_subarrays = 0;
            int go_right_i = i+1;
            int go_right_j = j+1;

            while(go_right_i < s.length() && go_right_j < t.length() && s[go_right_i] == t[go_right_j]){
                right_subarrays++;
                go_right_i++;
                go_right_j++;
            }
            ans += (1 + left_subarrays)*(1 + right_subarrays);
        }
        ans += recur(s, t, i+1, j, vis);
        ans += recur(s, t, i, j+1, vis);

        return ans;
        

    }
};