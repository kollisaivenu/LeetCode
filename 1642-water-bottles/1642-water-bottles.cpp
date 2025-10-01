class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int availableBottles = numBottles;
        while(availableBottles >= numExchange) {
            ans += availableBottles/numExchange;
            availableBottles = availableBottles/numExchange + availableBottles%numExchange;
        }

        return ans;
    }
};