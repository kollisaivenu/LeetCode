class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());

        unordered_map<int, bool>isPresent;
        isPresent[m-1] = true;
        for(int i=0;i<hFences.size();i++) {
            isPresent[hFences[i]-1] = true;
            isPresent[m-hFences[i]] = true;
            for(int j=i-1;j>=0;j--) {
                isPresent[hFences[i] - hFences[j]] = true;
            }
        }

        sort(vFences.begin(), vFences.end());
        int maxL = INT_MIN;
        for(int i=0;i<vFences.size();i++) {
            if(isPresent[vFences[i]-1]) {
                maxL = max(maxL, vFences[i]-1);
            }

            if(isPresent[n-vFences[i]]) {
                maxL = max(maxL, n-vFences[i]);
            }
            
            
            for(int j=i-1;j>=0;j--) {
                if(isPresent[vFences[i] - vFences[j]]) {
                    maxL = max(maxL, vFences[i] - vFences[j]);
                }
            }
        }

        if(isPresent[n-1]) {
            maxL = max(maxL, n-1);
        }

        if(maxL == INT_MIN) {
            return -1;
        }
        
        int area = ((long long)maxL*maxL)%1000000007;
        return area;
    }
};