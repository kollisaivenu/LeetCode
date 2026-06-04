class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int endTime = INT_MAX;
        pair<int, int>minLandTime;
        pair<int, int>minWaterTime;
        for(int i=0;i<landStartTime.size();i++) {
            if(endTime > landStartTime[i] + landDuration[i]) {
                minLandTime = make_pair(landStartTime[i], landStartTime[i] + landDuration[i]);
                endTime = landStartTime[i] + landDuration[i];
            }
        }
        endTime = INT_MAX;
        for(int i=0;i<waterStartTime.size();i++) {
            if(endTime > waterStartTime[i] + waterDuration[i]) {
                minWaterTime = make_pair(waterStartTime[i], waterStartTime[i] + waterDuration[i]);
                endTime = waterStartTime[i] + waterDuration[i];
            }
        }

        for(int i=0;i<waterStartTime.size();i++) {
            if(minLandTime.second <= waterStartTime[i]) {
                ans = min(ans, waterStartTime[i] + waterDuration[i]);
            } else {
                ans = min(ans, minLandTime.second + waterDuration[i]);
            }
        }

        for(int i=0;i<landStartTime.size();i++) {
            if(minWaterTime.second <= landStartTime[i]) {
                ans = min(ans, landStartTime[i] + landDuration[i]);
            } else {
                ans = min(ans, minWaterTime.second + landDuration[i]);
            }
        }

        return ans;
    }
};