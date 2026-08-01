class Solution {
public:
    int minimumPushes(string word) {
        map<char, int>freq;
        vector<pair<int, char>>pairs;
        for(char ch: word) {
            freq[ch]++;
        }

        for(auto [key, val]: freq) {
            pairs.push_back(make_pair(val, key));
        }

        sort(pairs.begin(), pairs.end());
        reverse(pairs.begin(), pairs.end());
        
        int assign = 0, ans = 0;
        for(auto [val, key]: pairs) {
            if(assign < 8) {
                ans += val;
            } else if(assign < 16) {
                ans += 2*val;
            } else if(assign < 24) {
                ans += 3*val;
            } else {
                ans += 4*val;
            }

            assign++;
        }

        return ans;
        
    }
};