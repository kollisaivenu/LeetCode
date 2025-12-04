class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost = 0;
        for(int i=0;i<colors.size();){
            int sum = 0, maxTime = INT_MIN, j = 0;
            for(j=i;colors[i] == colors[j];j++) {
                sum += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
            }

            if(i+1 != j) {
                minCost += (sum - maxTime);
            }

            i = j; 
        }

        return minCost;
    }
};