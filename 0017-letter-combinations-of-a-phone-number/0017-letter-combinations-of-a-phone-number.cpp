class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>letters {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        recur(0, "", ans, digits, letters);
        return ans;
    }

    void recur(int i, string poss, vector<string>&ans, string &digits, vector<string>&letters) {
        if(i == digits.size()) {
            ans.push_back(poss);
            return;
        }

        for(char ch: letters[digits[i]-'0']) {
            recur(i+1, poss+ch, ans, digits, letters);
        }
    }
};