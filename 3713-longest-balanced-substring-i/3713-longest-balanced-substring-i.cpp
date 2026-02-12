class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;

        for(int i=0;i<s.length();i++) {
            vector<int>freq(26, 0);
            for(int j=i;j<s.length();j++) {
                freq[s[j]-'a']++;
                int count = -1;
                bool valid = true;
                for(int k=0;k<26;k++) {
                    if(freq[k] == 0) {
                        continue;
                    } else {
                        if(count == -1) {
                            count = freq[k];
                        } else if(freq[k] != count) {
                            valid = false;
                            break;
                        }
                    }
                }

                if(valid) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};