class Solution {
public:
    long long maxScore(vector<int>& prices) {
        unordered_map<int, long long>diffSum;
        long long ans = LLONG_MIN;
        for(int i=0;i<prices.size();i++) {
            int diff = prices[i] - i;
            diffSum[diff] += prices[i];
            ans = max(ans, diffSum[diff]);
        }

        return ans;
    }
      
};