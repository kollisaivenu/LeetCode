class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int>freq;

        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        char ans;
        for(int i=0;i<t.length();i++){
            if(freq[t[i]] == 0){
                ans = t[i];
                break;
            }
            freq[t[i]]--;
        }

        return ans;
    }
};