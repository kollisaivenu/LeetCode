class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int>s1Odd(26, 0);
        vector<int>s1Even(26, 0);
        vector<int>s2Odd(26, 0);
        vector<int>s2Even(26, 0);

        for(int i=0;i<s1.length();i++) {
            if(i%2 == 0) {
                s1Even[s1[i]-'a']++;
                s2Even[s2[i]-'a']++;
            } else {
                s1Odd[s1[i]-'a']++;
                s2Odd[s2[i]-'a']++;
            }
        }
        
        for(int i=0;i<26;i++) {
            if(s1Odd[i] != s2Odd[i]) {
                return false;
            }

            if(s1Even[i] != s2Even[i]) {
                return false;
            }
        }

        return true;
    }
};