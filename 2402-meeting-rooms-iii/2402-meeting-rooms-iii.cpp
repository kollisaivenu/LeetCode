class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>freq(n, 0);
        priority_queue<pair<unsigned int, int>, vector<pair<unsigned int, int>>, greater<pair<unsigned int, int>>>pq;
        sort(meetings.begin(), meetings.end());
        for(int i=0;i<n;i++) {
            pq.push({0, i});
        }
        for(int i=0;i<meetings.size();i++) {
            unsigned int endTime = pq.top().first;
            int roomNo = pq.top().second;
            
            if(endTime <= meetings[i][0]) {
                vector<pair<int, int>>slots;
                int room = INT_MAX;
                while(!pq.empty() && pq.top().first <= meetings[i][0]) {
                    room = min(room, pq.top().second);
                    slots.push_back(pq.top());
                    pq.pop();
                }
                pq.push({meetings[i][1], room});
                freq[room]++;
                for(int i=0;i<slots.size();i++) {
                    if(slots[i].second == room) {
                        continue;
                    }

                    pq.push(slots[i]);
                }
            } else {
                pq.push({(endTime + (unsigned int)(meetings[i][1]-meetings[i][0])), roomNo});
                pq.pop();
                freq[roomNo]++;
            }
            
            
        }
        
        int noOfMeetings = freq[0];
        int maxMeetingRoom = 0;
        for(int i=1;i<n;i++) {
            if(freq[i] > noOfMeetings) {
                maxMeetingRoom = i;
                noOfMeetings = freq[i];
            }
        }

        return maxMeetingRoom;
    }
};