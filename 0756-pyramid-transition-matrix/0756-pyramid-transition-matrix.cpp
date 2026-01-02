class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>>possibleTopChar;

        for(int i=0;i<allowed.size();i++) {
            string key = {allowed[i][0], allowed[i][1]};
            possibleTopChar[key].push_back(allowed[i][2]);
        }
        string top;
        top.reserve(bottom.length()-1);
        return check(bottom, top, possibleTopChar);
    }

    bool check(string &bottom, string top, unordered_map<string, vector<char>>&possibleTopChar) {
        if(top.length() == bottom.length() - 1) {
            if(top.length() == 1) {
                return true;
            } else {
                string newTop;
                newTop.reserve(bottom.length()-1);
                return check(top, newTop, possibleTopChar);
            }
        }

        bool possible = false;
        int index = top.length()+1;
        string key = {bottom[index-1], bottom[index]};
        for(int i=0;i<possibleTopChar[key].size();i++) {
            possible = possible || check(bottom, top + possibleTopChar[key][i], possibleTopChar);
        }
        return possible;
    }
};