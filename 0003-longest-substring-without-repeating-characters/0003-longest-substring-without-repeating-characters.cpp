class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>freq;
        int i=0,j=0,ans=0;

        while(j<s.length()) {
            freq[s[j]]++;
            while(freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;   
        }

        return ans;
    }

    bool isvalid(unordered_map<char, bool>&present, int i , int j) {
        if(j-i+1 == present.size()) {
            return true;
        }

        return false;

    }
};