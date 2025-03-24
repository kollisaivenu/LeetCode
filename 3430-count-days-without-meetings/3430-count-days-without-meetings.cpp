class Solution {
public:
    bool static compareVector(vector<int>a, vector<int>b){
        return a[0] < b[0];
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compareVector);
        vector<int> meeting = meetings[0];
        int busyDays = 0;
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0] <= meeting[1] && meeting[1]<meetings[i][1]){
                meeting[1] = meetings[i][1];
            } else if(meetings[i][0] > meeting[1]){
                busyDays += (meeting[1] - meeting[0] + 1);
                meeting = meetings[i];
            }
        }
        busyDays += (meeting[1] - meeting[0] + 1);
        return days-busyDays;
    }
};