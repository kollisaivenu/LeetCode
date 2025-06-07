class Solution {
public:
    static bool comparePairs(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }

    string clearStars(string s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comparePairs)>pq(comparePairs);
        vector<int>includeIndex(s.length(), 1);
        string ans = "";

        for(int i=0;i<s.length();i++){
            if(s[i] == '*'){
                includeIndex[i] = 0;
                includeIndex[pq.top().second] = 0;
                pq.pop();
            } else {
                pq.push(make_pair(s[i] - 'a', i));
            }
        }

        for(int i=0;i<s.length();i++){
            if(includeIndex[i] == 1){
                ans += s[i];
            }
        }

        return ans;      
    }
};