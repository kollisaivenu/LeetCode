class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        stk.push(pushed[0]);

        int i=1, j=0;
        while(i < pushed.size() && j < popped.size()) {
            if(!stk.empty() && popped[j] == stk.top()) {
                stk.pop();
                j++;
            } else  {
                stk.push(pushed[i]);
                i++;
            }
        }
        cout<<"came here\n";
        if(i < pushed.size() && j == popped.size()) {
            return true;
        } else if (i == pushed.size()) {
            while(!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }

            if((stk.empty() && j < popped.size()) || (!stk.empty() && stk.top() != popped[j])) {
                return false;
            }

            return true;
        }
        return false;
    }
};