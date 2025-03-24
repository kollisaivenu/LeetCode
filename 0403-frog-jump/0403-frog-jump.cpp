class Solution {
public:
    vector<vector<int>>dp;
    map<int, int>stones2index;
    bool canCross(vector<int>& stones) {
        int max_leap = stones.size();
        for(int i=0;i<stones.size();i++){
            stones2index[stones[i]] = i;
        }
        dp.resize(stones.size(), vector<int>(max_leap, -1));
        return recursion(stones, 0, 0);
    }

    int recursion(vector<int>& stones, int i, int curr_leap){
        bool ans = 0;
        if(i == stones.size()-1){
            dp[i][curr_leap] = 1;
            return dp[i][curr_leap];
        }

        if((i == 0) && (stones[i+1] - stones[i] == 1)){
            if(dp[i+1][1] == -1){
                dp[i+1][1] = recursion(stones, i+1, 1);
            }
            ans = ans | dp[i+1][1];
        } else {
            if(stones2index[stones[i]+curr_leap] > i){
                if(dp[stones2index[stones[i]+curr_leap]][curr_leap] == -1){
                    dp[stones2index[stones[i]+curr_leap]][curr_leap] = recursion(stones, stones2index[stones[i]+curr_leap], curr_leap);
                }

                ans = ans | dp[stones2index[stones[i]+curr_leap]][curr_leap];
            }
            if(stones2index[stones[i]+curr_leap+1] > i){
                if(dp[stones2index[stones[i]+curr_leap+1]][curr_leap+1] == -1){
                    dp[stones2index[stones[i]+curr_leap+1]][curr_leap+1] = recursion(stones, stones2index[stones[i]+curr_leap+1], curr_leap+1);
                }

                ans = ans | dp[stones2index[stones[i]+curr_leap+1]][curr_leap+1];
            } 
            if(stones2index[stones[i]+curr_leap-1] > i){
                if(dp[stones2index[stones[i]+curr_leap-1]][curr_leap-1] == -1){
                    dp[stones2index[stones[i]+curr_leap-1]][curr_leap-1] = recursion(stones, stones2index[stones[i]+curr_leap-1], curr_leap-1);
                }

                ans = ans | dp[stones2index[stones[i]+curr_leap-1]][curr_leap-1];
            }
        }
        dp[i][curr_leap] = ans;
        return ans;
    }
};