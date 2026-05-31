class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = INT_MIN;
        int buy = prices[0];

        for(int i=0;i<prices.size();i++) {
            price = max(prices[i]-buy, price);
            buy = min(prices[i], buy);
        }
        return price;
    }
};