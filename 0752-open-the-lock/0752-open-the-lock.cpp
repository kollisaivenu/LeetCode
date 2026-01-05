class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool>isDeadEnd;

        for(int i=0;i<deadends.size();i++) {
            isDeadEnd[deadends[i]] = true;

            if(deadends[i] == "0000") {
                return -1;
            }
        }

        queue<pair<string, int>>q;
        q.push(make_pair("0000", 0));

        int ans = -1;

        while(!q.empty()) {
            pair<string, int>p = q.front();
            q.pop();
            
            if(p.first == target) {
                ans = p.second;
                break;
            }

            vector<string>combos = getCombinations(p.first);

            for(int i=0;i<combos.size();i++) {
                if(!isDeadEnd[combos[i]]){
                    isDeadEnd[combos[i]] = true;
                    q.push(make_pair(combos[i], p.second+1));
                }
            }
            
        }
        return ans;
    }

    vector<string> getCombinations(string str) {
        vector<string>combos;

        for(int i=0;i<4;i++){
            if(str[i] == '9') {
                string newStr1 = str;
                string newStr2 = str;
                newStr1[i] = '8';
                newStr2[i] = '0';
                combos.push_back(newStr1);
                combos.push_back(newStr2);
            } else if(str[i] == '0') {
                string newStr1 = str;
                string newStr2 = str;
                newStr1[i] = '9';
                newStr2[i] = '1';
                combos.push_back(newStr1);
                combos.push_back(newStr2);
            } else {
                string newStr1 = str;
                string newStr2 = str;
                
                newStr1[i] = (char)((int)str[i]+1);
                newStr2[i] = (char)((int)str[i]-1);
                combos.push_back(newStr1);
                combos.push_back(newStr2);
            }

        }

        return combos;
        
    }
};