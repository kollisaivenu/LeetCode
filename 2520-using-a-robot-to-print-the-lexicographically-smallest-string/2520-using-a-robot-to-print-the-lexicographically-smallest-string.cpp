class Solution {
public:
    string robotWithString(string s) {
        stack<char>stk1,stk2;
        string ans = "";

        for(int i=0;i<s.size();i++){

            if(stk1.empty() || stk1.top() <= s[i]){
                stk1.push(s[i]);
            } else if(stk1.top() > s[i]){

                while(!stk1.empty() && stk1.top() > s[i]){
                    stk1.pop();
                }
                stk1.push(s[i]);
            }
        }

        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }

        for(int i=0;i<s.size();i++){
            
            if(!stk2.empty() && s[i] == stk2.top()){
                ans += s[i];
                stk2.pop();

                while(!stk1.empty() && !stk2.empty() && stk1.top() <= stk2.top()){
                    ans += stk1.top();
                    stk1.pop();
                }
            } else {
                stk1.push(s[i]);
            }
        }

        while(!stk1.empty()){
            ans += stk1.top();
            stk1.pop();
        }

        return ans;
    }
};