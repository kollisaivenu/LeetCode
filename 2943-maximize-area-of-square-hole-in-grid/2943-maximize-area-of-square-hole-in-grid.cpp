class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        int maxHCount = INT_MIN;
        for(int i=0;i<hBars.size();i++) {
            int hcount = 1;
            for(int j=i+1;j<hBars.size();j++) {
                if(hBars[j] == 1 + hBars[j-1]) {
                    hcount++;
                } else {
                    break;
                }
            }
            maxHCount = max(maxHCount, hcount+1);
        }
        
        sort(vBars.begin(), vBars.end());
        int maxVCount = INT_MIN;
        for(int i=0;i<vBars.size();i++) {
            int vcount = 1;
            for(int j=i+1;j<vBars.size();j++) {
                if(vBars[j] == 1 + vBars[j-1]) {
                    vcount++;
                } else {
                    break;
                }
            }
            maxVCount = max(maxVCount, vcount+1);
        }
        
        return min(maxVCount, maxHCount)*min(maxVCount, maxHCount);
    }
};