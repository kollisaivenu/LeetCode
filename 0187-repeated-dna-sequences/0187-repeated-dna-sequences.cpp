class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string>substr_set;
        set<string>already_present;
        vector<string>ans;
        for(int i=0;i<s.length();i++) {
            string ss = s.substr(i, 10);

            if(substr_set.contains(ss)) {
                if(!already_present.contains(ss)) {
                    ans.push_back(ss);
                    already_present.insert(ss);
                }
                
                continue;
            }

            substr_set.insert(ss);
        }

        return ans;
    }
};