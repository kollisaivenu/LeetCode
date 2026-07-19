class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> vis(26, false);
        vector<int> num(26, 0);

        for(char ch: s) {
            num[ch-'a']++;
        }

        stack<char> stk;

        for(char ch: s) {
            if(!vis[ch-'a']) {
                while(!stk.empty() && stk.top() > ch) {
                    if(num[stk.top()-'a'] > 0) {
                        vis[stk.top()-'a'] = false;
                        stk.pop();
                    } else {
                        break;
                    }
                }

                vis[ch-'a'] = true;
                stk.push(ch);
            }
            num[ch-'a'] -= 1;
        }

        string ans = "";
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }


        return ans;
        
    }
};