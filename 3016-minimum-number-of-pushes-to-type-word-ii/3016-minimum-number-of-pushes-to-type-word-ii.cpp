class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26, 0);
        for(char ch: word) {
            freq[ch-'a']++;
        }

        sort(freq.rbegin(), freq.rend());
        int assign = 0, ans = 0;
        for(int val: freq) {
            if(val == 0) break;
            
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