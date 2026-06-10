class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freqp(26, 0);
        vector<int>freqs(26, 0);
        vector<int>ans;
        if(p.size() > s.size()) {
            return ans;
        }
        for(char ch: p) {
            freqp[ch-'a']++;
        }

        for(int i=0;i<p.size()-1;i++) {
            freqs[s[i]-'a']++;
        }

        int start = 0;
        int end = p.size()-1;
        
        while(end<s.size()) {
            freqs[s[end]-'a']++;
            end++;
            if(check(freqs, freqp)) {
                ans.push_back(start);
            }

            freqs[s[start]-'a']--;
            start++;    
        }

        return ans;
    }

    bool check(vector<int>&freqs, vector<int>&freqp) {
        for(int i=0;i<26;i++) {
            if(freqs[i] != freqp[i]) {
                return false;
            }
        }

        return true;
    }
};