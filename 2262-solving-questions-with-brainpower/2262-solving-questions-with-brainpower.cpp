class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1, 0);

        for(int i=questions.size()-1;i>=0;i--){
            dp[i] = max(questions[i][0] + getEntry(dp, questions, i+questions[i][1]+1), getEntry(dp, questions, i+1));
        }
        return dp[0];
    }
    long long getEntry(vector<long long>&dp, vector<vector<int>>&questions, int index){
        if(index >= questions.size()){
            return 0;
        }
        return dp[index];
    }
};