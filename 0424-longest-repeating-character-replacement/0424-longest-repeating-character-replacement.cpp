class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int i=0, j=0;
        int ans = INT_MIN;
        while(j<s.length()){
            freq[s[j]-'A']++;
            while(!isvalid(freq, k)) {
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }

    bool isvalid(vector<int>&freq, int k) {
        int total = 0;
        int maxChar = 0;
        for(int i=0;i<26;i++) {
            total += freq[i];
            maxChar = max(maxChar, freq[i]);
        }

        if(total-maxChar <= k) {
            return true;
        }

        return false;
    }

    
};