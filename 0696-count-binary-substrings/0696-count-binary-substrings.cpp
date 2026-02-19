class Solution {
public:
    int countBinarySubstrings(string s) {
        stack<char>stk;
        int count = 0;

        for(int i=0;i<s.length();) {
            if(stk.empty()) {
                stk.push(s[i++]);
                while(i < s.length() && stk.top() == s[i]) {
                    stk.push(s[i]);
                    i++;
                }
            } else {
                int j = i;
                while(j < s.length() && !stk.empty() && stk.top() != s[j]) {
                    stk.pop();
                    j++;
                    count++;
                }

                while(!stk.empty()) {
                    stk.pop();
                }
            } 
        }

        return count;
    }
};