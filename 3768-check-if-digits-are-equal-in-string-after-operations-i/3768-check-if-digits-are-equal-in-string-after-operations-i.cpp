class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() != 2) {
            s = getNextString(s);
        }

        return s[0] == s[1];
        
    }
    string getNextString(string &s){
        string s1 = "";
        
        for(int i=1;i<s.length();i++){
            int no1 = s[i]-'0';
            int no2 = s[i-1]-'0';
            s1 += to_string((no1+no2)%10);
        }

        return s1;
    }
};