class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<bool>removed(intervals.size(), false);
        for(int i=0;i<intervals.size();i++) {
            for(int j=0;j<intervals.size();j++) {
                if(i != j && !removed[j]) {
                    if(intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]) {
                        removed[j] = true;
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<removed.size();i++) {
            if(!removed[i]) {
                ans++;
            }
        }

        return ans;
    }
};