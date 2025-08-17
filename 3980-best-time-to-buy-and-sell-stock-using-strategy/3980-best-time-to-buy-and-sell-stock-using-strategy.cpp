class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long right_profit = 0;
        long long left_profit = 0;
        long long curr_profit = 0;

        for(int i=0;i<prices.size();i++){
            curr_profit += prices[i]*strategy[i];
        }

        for(int i=k;i<prices.size();i++){
            right_profit += prices[i]*strategy[i];
        }

        long long sum_of_right = 0;

        for(int i=k/2;i<k;i++){
            sum_of_right += prices[i];
        }

        int x=0, y=k/2, z=k;
        curr_profit = max(curr_profit, left_profit + sum_of_right + right_profit);
        for(;z<prices.size();x++, y++, z++){
            curr_profit = max(curr_profit, left_profit + sum_of_right + right_profit);
            left_profit += prices[x]*strategy[x];
            right_profit -= prices[z]*strategy[z];
            sum_of_right -= prices[y];
            sum_of_right += prices[z];
        }

        curr_profit = max(curr_profit, left_profit + sum_of_right + right_profit);

        return curr_profit;
        
    }
};