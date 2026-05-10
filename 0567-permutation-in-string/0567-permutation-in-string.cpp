class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26, 0);
        vector<int>freq2(26, 0);

        if(s1.length() > s2.length()) {
            return false;
        }
        for(int i=0;i<s1.length();i++) {
            freq[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        if(isvalid(freq, freq2)) {
            return true;
        }

        for(int i=0,j=s1.length();j<s2.length();i++,j++) {
            freq2[s2[i]-'a']--;
            freq2[s2[j]-'a']++;

            if(isvalid(freq, freq2)) {
                return true;
            }
        }

        return false;
    }

    bool isvalid(vector<int>&freq, vector<int>&freq2) {
        for(int i=0;i<26;i++) {
            if(freq[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};