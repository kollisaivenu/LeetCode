class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool>present;
        int i=0,j=0, ans = 0;

        while(j<s.length()) {
            if(present[s[j]] == true) {
                while(s[i] != s[j]) {
                    present.erase(s[i]);
                    i++;
                }
                present.erase(s[i]);
                i++;
            }
            present[s[j]] = true;
            ans = max(ans, j-i+1);
            j++;   
        }

        return ans;
    }
};