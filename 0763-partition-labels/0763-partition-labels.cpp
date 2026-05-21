class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        for(int i=0;i<s.length();i++) {
            freq1[s[i]-'a']++;
        }

        vector<int>ans;
        int start = 0;
        for(int i=0;i<s.length();i++) {
            freq2[s[i]-'a']++;

            if(valid(freq1, freq2)) {
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;        
    }

    bool valid(vector<int>&freq1, vector<int>&freq2) {
        for(int i=0;i<26;i++) {
            if(freq1[i] == freq2[i]) {
                continue;
            } else if (freq1[i] > 0 && freq2[i] == 0) {
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};