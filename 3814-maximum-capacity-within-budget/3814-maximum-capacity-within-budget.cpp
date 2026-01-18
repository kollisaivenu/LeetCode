class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int, int>>costCapacity;
        for(int i=0;i<costs.size();i++) {
            costCapacity.push_back(make_pair(costs[i], capacity[i]));
        }
        vector<int>maxCap(capacity.size(), 0);
        sort(costCapacity.begin(), costCapacity.end());
        maxCap[0] = costCapacity[0].second;
        int ans = 0;
        for(int i=0;i<costCapacity.size();i++) {
            if(i > 0) {
                maxCap[i] = max(maxCap[i-1], costCapacity[i].second);
            }

            if(costCapacity[i].first < budget) {
                ans = max(ans, costCapacity[i].second);
            } else {
                break;
            }

            int low = 0, high = i-1;
            int ind = -1;
            while(low<=high) {
                int mid = low + (high-low)/2;

                if(costCapacity[mid].first + costCapacity[i].first < budget) {
                    ind = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }

            if(ind != -1) {
                ans = max(ans, costCapacity[i].second+maxCap[ind]);
            }
        }

        return ans;
    }
};