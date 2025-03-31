class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(weights.size() <= k){
            return 0;
        }
        priority_queue<long long>maxScore;
        priority_queue<long long, vector<long long>, greater<long long>>minScore;

        for(int i=1;i<weights.size();i++){
            maxScore.push(weights[i]+weights[i-1]);
            minScore.push(weights[i]+weights[i-1]);
        }
        long long maxScoreSum = 0, minScoreSum = 0;
        k = k-1;
        while(k){
            minScoreSum += minScore.top();
            maxScoreSum += maxScore.top();
            minScore.pop();
            maxScore.pop();
            k--;
        }

        return maxScoreSum - minScoreSum;
        
    }
};