class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = INT_MIN;
        for(int i=0;i<k;i++){
            int maxAlloys = INT_MAX;
            
            for(int j=0;j<n;j++){
                maxAlloys = min(maxAlloys, (stock[j] + budget));
            }

            int low = 0, high = maxAlloys;

            while(low<=high) {
                int mid = low+(high-low)/2;
                if(isValid(mid, composition[i], stock, cost, budget)) {
                    
                    ans = max(ans, mid);
                    low = mid + 1;
                } else {
                    high = mid-1;
                }
            }
        }

        return ans; 
    }

    bool isValid(int count, vector<int>&composition, vector<int>&stock, vector<int>& cost, int budget) {
        long long totalCost = 0;
        for(int i=0;i<composition.size();i++) {
            totalCost += (max((long long)((long long)count*(long long)composition[i] - stock[i]), (long long)0))*(long long)cost[i];
        }

        if(totalCost <= budget) {
            return true;
        }

        return false;
    }
};