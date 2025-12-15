class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;

        for(int i=0;i<prices.size();) {
            long long size = 1;
            int j = i+1;
            for(;j<prices.size();j++) {
                if(prices[j-1] - prices[j] == 1){
                    size++;
                } else {
                    break;
                }
            }
            ans += (size)*(size+1)/2;
            i = j;
        }

        return ans;
    }
};