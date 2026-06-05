class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>>pq;
        int ans = 1;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++) {
            if(pq.top() <= intervals[i][0]) {
                pq.pop();
                pq.push(intervals[i][1]);
            } else {
                pq.push(intervals[i][1]);
            }

            ans = max(ans, (int)pq.size());
        }

        return ans;
        
    }
};