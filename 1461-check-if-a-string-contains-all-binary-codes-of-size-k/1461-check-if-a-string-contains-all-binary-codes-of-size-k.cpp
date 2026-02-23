class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>set;
        if(s.length() < k) {
            return false;
        }
        string substr;
        substr.reserve(k);
        for(int i=0;i<k;i++){
            substr += s[i];
        }

        set.insert(substr);
        for(int j=k;j<s.length();j++){
            shiftleft(substr);
            substr[k-1] = s[j];
            set.insert(substr);
        }

        if(set.size() == 1 << k){
            return true;
        }

        return false;
        
    }
    void shiftleft(string& s){
        for(int i=1;i<s.length();i++){
            s[i-1] = s[i];
        }
    }
};