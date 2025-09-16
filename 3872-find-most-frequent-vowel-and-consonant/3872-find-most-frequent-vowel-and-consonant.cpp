class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26, 0);
        int maxVowel = INT_MIN, maxConso = INT_MIN;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(isVowel(i+97)){
                maxVowel = max(freq[i], maxVowel);
            } else {
                maxConso = max(freq[i], maxConso);
            }
        }
        return maxVowel + maxConso;
    }

    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }

        return false;
    }
};