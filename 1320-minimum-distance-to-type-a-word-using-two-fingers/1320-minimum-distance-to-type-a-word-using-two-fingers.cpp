class Solution {
public:
    int minimumDistance(string word) {
        vector<pair<int, int>>loc;
        vector<vector<vector<int>>>dp(word.length()+1, vector<vector<int>>(27, vector<int>(27, -1)));
        for(int i=0;i<5;i++) {
            for(int j=0;j<6;j++) {
                loc.push_back(make_pair(i, j));
            }
        }
    
        return recur(word, 0, 'a', 'a', loc, dp);
    }

    int recur(string &str, int i, char f1, char f2, vector<pair<int, int>>&loc, vector<vector<vector<int>>>&dp) {
        if(i == str.length()) {
            return 0;
        }

        int ans = INT_MAX;
        if(f1 == 'a') {
            if(dp[i+1][getIndex(str[i])][getIndex(f2)] == -1) {
                dp[i+1][getIndex(str[i])][getIndex(f2)] = recur(str, i+1, str[i], f2, loc, dp);
            }
            ans = min(ans, dp[i+1][getIndex(str[i])][getIndex(f2)]);
        } else {
            if(dp[i+1][getIndex(str[i])][getIndex(f2)] == -1) {
                dp[i+1][getIndex(str[i])][getIndex(f2)] = recur(str, i+1, str[i], f2, loc, dp);
            }
            int cost = dist(str[i], f1, loc);
            ans = min(ans, cost + dp[i+1][getIndex(str[i])][getIndex(f2)]);
        }

        if(f2 == 'a') {
            if(dp[i+1][getIndex(f1)][getIndex(str[i])] == -1) {
                dp[i+1][getIndex(f1)][getIndex(str[i])] = recur(str, i+1, f1, str[i], loc, dp);
            }
            ans = min(ans, dp[i+1][getIndex(f1)][getIndex(str[i])]);
        } else {
            if(dp[i+1][getIndex(f1)][getIndex(str[i])] == -1) {
                dp[i+1][getIndex(f1)][getIndex(str[i])] = recur(str, i+1, f1, str[i], loc, dp);
            }
            int cost = dist(str[i], f2, loc);
            ans = min(ans, cost + dp[i+1][getIndex(f1)][getIndex(str[i])]);
        }

        return ans;
    }

    int dist(char f1, char f2, vector<pair<int, int>>&loc) {
        pair<int, int>l1 = loc[f1-'A'];
        pair<int, int>l2 = loc[f2-'A'];
        return abs(l1.first - l2.first) + abs(l1.second - l2.second);
    }

    int getIndex(char ch) {
        if (ch == 'a') {
            return 0;
        } else {
            return (ch - 'A')+1;
        }
    }
};