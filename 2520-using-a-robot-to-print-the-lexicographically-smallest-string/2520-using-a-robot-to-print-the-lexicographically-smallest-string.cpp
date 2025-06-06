class Solution {
public:
    string robotWithString(string s) {
        stack<char>stk,stk2;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(stk.empty() || stk.top() <= s[i]){
                stk.push(s[i]);
            } else if(stk.top() > s[i]){
                while(!stk.empty() && stk.top() > s[i]){
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }

        while(!stk.empty()){
            //cout<<stk.top()<<"\n";
            stk2.push(stk.top());
            stk.pop();
        }

        for(int i=0;i<s.size();i++){
            if(!stk2.empty() && s[i] == stk2.top()){
                ans += s[i];
                stk2.pop();

                while(!stk.empty() && !stk2.empty() && stk.top() <= stk2.top()){
                    ans += stk.top();
                    stk.pop();
                }
            } else {
                stk.push(s[i]);
            }
        }

        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};