class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string, bool>m;
        

        if(s.length() < k) {
            return false;
        }
        string ans;
        ans.reserve(k);
        for(int i=0;i<k;i++){
            ans += s[i];
        }

        m[ans] = true;
        for(int j=k;j<s.length();j++){
            shiftleft(ans);
            ans[k-1] = s[j];
            m[ans] = true;
        }

        if(m.size() == 1 << k){
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