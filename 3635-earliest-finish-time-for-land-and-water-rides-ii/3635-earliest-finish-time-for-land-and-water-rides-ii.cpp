class Solution {
public:
    static bool cmp(pair<int, int>&a, pair<int, int>&b) {
        return a.second < b.second;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        vector<pair<int, int>>land;
        vector<pair<int, int>>water;
        for(int i=0;i<landStartTime.size();i++) {
            land.push_back(make_pair(landStartTime[i], landStartTime[i]+landDuration[i]));
        }

        for(int i=0;i<waterStartTime.size();i++) {
            water.push_back(make_pair(waterStartTime[i], waterStartTime[i]+waterDuration[i]));
        }

        sort(land.begin(), land.end(), cmp);
        sort(water.begin(), water.end(), cmp);

        for(int i=0;i<waterStartTime.size();i++) {
            if(land[0].second <= waterStartTime[i]) {
                ans = min(ans, waterStartTime[i] + waterDuration[i]);
            } else {
                ans = min(ans, land[0].second + waterDuration[i]);
            }
        }

        for(int i=0;i<landStartTime.size();i++) {
            if(water[0].second <= landStartTime[i]) {
                ans = min(ans, landStartTime[i] + landDuration[i]);
            } else {
                ans = min(ans, water[0].second + landDuration[i]);
            }
        }

        return ans;
    }
};