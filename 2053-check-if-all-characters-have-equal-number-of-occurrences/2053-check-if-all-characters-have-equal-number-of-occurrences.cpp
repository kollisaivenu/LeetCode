class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>freq(26, 0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-97]++;
        }

        for(int i=0;i<26;i++){
            if((freq[i] == freq[s[0]-97]) || freq[i] == 0){
                continue;
            } else {
                return false;
            }
        }

        return true;
    }
};