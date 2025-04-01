class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        //return maxPoints(0, questions);
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
    long long maxPoints(int index, vector<vector<int>>& questions){
        if(index >= questions.size()){
            return 0;
        }

        return max(questions[index][0] + maxPoints(index+questions[index][1]+1, questions), 
                   maxPoints(index+1, questions));
    }
};