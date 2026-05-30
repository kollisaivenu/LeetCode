class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX;
        int ans = INT_MAX;
        while(low<=high) {
            int mid = low + (high-low)/2;

            if(isvalid(piles, h, mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    bool isvalid(vector<int>&piles, int h, int k) {
        int current_h = 0;
        for(int i=0;i<piles.size();i++) {
            current_h += piles[i]/k;
            if(piles[i]%k != 0) {
                current_h += 1;
            }
        }
        
        if(current_h <= h) {
            return true;
        }
        return false;
    }
};