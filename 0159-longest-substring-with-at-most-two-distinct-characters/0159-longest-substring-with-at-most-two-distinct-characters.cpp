class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int>freqUpper(26, 0);
        vector<int>freqLower(26, 0);
        int i=0, j=0;
        int ans = INT_MIN;
        while(j < s.length()) {
            if(isupper(s[j])) {
                freqUpper[s[j]-'A']++;
            } else {
                freqLower[s[j]-'a']++;
            }
            
            while(!check(freqUpper, freqLower)) {
                if(isupper(s[i])) {
                    freqUpper[s[i]-'A']--;
                } else {
                    freqLower[s[i]-'a']--;
                }
                i++;
            }

            ans = max(ans, j-i+1);
            j++;    
        }

        return ans;
    }

    bool check(vector<int>&freqUpper, vector<int>&freqLower) {
        int count = 0;

        for(int i=0;i<26;i++) {
            if(freqLower[i] > 0) {
                count++;
            }

            if(freqUpper[i] > 0) {
                count++;
            }
        }

        if(count <= 2) {
            return true;
        }

        return false;
    }
};