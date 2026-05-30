class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subans;
        getPalindromes(0, s, subans, ans);
        return ans;
 
    }
    void getPalindromes(int index, string& s, vector<string> subans, vector<vector<string>>&ans) {
        if(index == s.length()) {
            ans.push_back(subans);
            return;
        }

        for(int i=index;i<s.length();i++) {
            if(isPalindrome(s, index, i)) {
                subans.push_back(getSubString(s, index, i));
                getPalindromes(i+1, s, subans, ans);
                subans.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end) {
        for(int i=start, j=end;i<=j;i++, j--) {
            if(s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }

    string getSubString(string &s, int start, int end) {
        string ss = "";

        for(int i=start;i<=end;i++) {
            ss += s[i];
        }

        return ss;
    }
    
};