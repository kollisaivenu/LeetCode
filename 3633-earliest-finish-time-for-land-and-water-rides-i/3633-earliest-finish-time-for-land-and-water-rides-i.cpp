class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i=0;i<landStartTime.size();i++) {
            for(int j=0;j<waterStartTime.size();j++) {
                int time = max(landStartTime[i]+landDuration[i], waterStartTime[j]) + waterDuration[j];
                ans = min(ans, time);
            }
        }

        for(int i=0;i<waterStartTime.size();i++) {
            for(int j=0;j<landStartTime.size();j++) {
                int time = max(waterStartTime[i]+waterDuration[i], landStartTime[j]) + landDuration[j];
                ans = min(ans, time);
            }
        }

        return ans;
        
    }
};