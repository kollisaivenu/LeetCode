class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        priority_queue<int, vector<int>, greater<int>>pq(trainers.begin(), trainers.end());
        int ans = 0;

        for(int i=0;i<players.size();i++){
            while(!pq.empty() && players[i] > pq.top()){
                pq.pop();
            }

            if(pq.empty()){
                break;
            } else {
                ans++;
                pq.pop();
            }
        }

        return ans;
    }
};