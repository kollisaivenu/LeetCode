class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = 0;
        if(cost1+cost2 < costBoth) {
            cost += min((long long)need1, (long long)need2)*(cost1+cost2);
        } else {
            cost += min((long long)need1, (long long)need2)*(costBoth);
        }

        if(need1 < need2) {
            if(cost2 < costBoth) {
                cost += ((long long)need2 - (long long)need1)*cost2;
            } else {
                cost += ((long long)need2 - (long long)need1)*costBoth;
            }
        } else {
            if(cost1 < costBoth) {
                cost += ((long long)need1 - (long long)need2)*cost1;
            } else {
                cost += ((long long)need1 - (long long)need2)*costBoth;
            }
        }

        return cost;
    }
};