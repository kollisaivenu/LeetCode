class Solution {
public:
    bool checkOnesSegment(string s) {
        bool one = true;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '1' && one) {
                continue;
            } else if(s[i] == '0' && one) {
                one = false;
            } else if(s[i] == '1' && !one) {
                return false;
            }
        }

        return true;
    }
};