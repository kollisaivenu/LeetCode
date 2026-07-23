class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>sess;
        sess.reserve(s.length()+2);
        int ones = 0, count = 0;
        char curr = '2';

        if(s[0] == '0') {
            sess.push_back(-1);
        }

        for(int i=0;i<s.length();i++) {
            if(s[i] == '1') {
                ones++;
            }

            if(curr == '2') {
                count++;
                curr = s[i];
            } else if(curr == s[i]) {
                count++;
            } else if(curr != s[i]) {
                if(curr == '0') {
                    sess.push_back(count);
                } else {
                    sess.push_back(-count);
                }
                
                count = 1;
                curr = s[i];
            }

            if(i == s.length()-1) {
                if(curr == '0') {
                    sess.push_back(count);
                } else {
                    sess.push_back(-count);
                }
            }
        }
        
        if(s[0] == '1') {
            sess[0]--;
        }
        if(s[s.length()-1] == '1') {
            sess[sess.size()-1]--;
        } else {
            sess.push_back(-1);
        }
        
        int ans = ones;
        for(int i=2;i<(int)sess.size()-2;i++) {
            if(sess[i] < 0) {
                ans = max(ans, ones + sess[i-1] + sess[i+1]);
            }
        }

        return ans;
    }
};