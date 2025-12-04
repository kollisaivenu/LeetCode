class Solution {
public:
    int countCollisions(string directions) {
        stack<char>stk;

        if(directions[0] != 'L') stk.push(directions[0]);
        int collisions = 0;

        for(int i=1;i<directions.size();i++){
            if(directions[i] == 'L') {
                if(stk.empty()) {
                    continue;
                } else if(stk.top() == 'R') {
                    collisions += 2;
                    stk.pop();

                    while(!stk.empty() && stk.top() == 'R') {
                        stk.pop();
                        collisions++;
                    }

                    stk.push('S');
                } else if(stk.top() == 'S') {
                    collisions++;
                }
            } else if(directions[i] == 'S') {
                if(stk.empty() || stk.top() == 'S') {
                    stk.push('S');
                } else if(stk.top() == 'R') {
                    while(!stk.empty() && stk.top() == 'R'){
                        collisions++;
                        stk.pop();
                    }
                    stk.push('S');
                }
            } else if(directions[i] == 'R') {
                stk.push('R');
            }
        }
        
        return collisions;
    }
};