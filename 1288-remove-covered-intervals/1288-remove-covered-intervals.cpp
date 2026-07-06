class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int remove = 0;
        for(int i=0;i<intervals.size();) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j=i+1;
            while(j < intervals.size()) {
                if(intervals[j][1] <= end) {
                    remove++;
                } else {
                    break;
                }
                j++;
            }

            i = j;
        }

        return intervals.size()-remove;
    }
};