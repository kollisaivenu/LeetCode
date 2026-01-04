class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>groups;
        vector<bool>vis(strings.size(), false);
        for(int i=0;i<strings.size();i++) {
            if(vis[i] == false) {
                vector<string>subGroup;
                vis[i] = true;
                subGroup.push_back(strings[i]);
                for(int j=i+1;j<strings.size();j++) {
                    if(vis[j] == false) {
                        if(check(strings[i], strings[j])) {
                            subGroup.push_back(strings[j]);
                            vis[j] = true;
                        }
                    }
                }
                groups.push_back(subGroup);
            }   
        }
        return groups;   
    }

    bool check(string &str1, string &str2) {
        if(str1.length() != str2.length()) {
            return false;
        }

        int diff = ((str1[0] - str2[0])+26)%26;

        for(int i=1;i<str1.length();i++) {
            if(((str1[i] - str2[i])+26)%26 != diff) {
                return false;
            }
        }

        return true;
    }
};