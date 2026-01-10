class Solution {
public:
    string largestEven(string s) {
        string ans = "";
        bool guaranteedEven = false;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == '1' && !guaranteedEven) {
                continue;
            } else if(s[i] == '2' && !guaranteedEven) {
                ans += '2';
                guaranteedEven = true;
            } else if(guaranteedEven) {
                ans += s[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};