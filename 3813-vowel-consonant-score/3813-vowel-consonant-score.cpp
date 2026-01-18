class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0, c=0;
        for(char ch: s) {
            if(isvowel(ch)) {
                v++;
            } else if(isconso(ch)) {
                c++;
            }
        }
        
        if(c == 0) {
            return 0;
        }

        return floor((double)v/c);
        
    }

    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }

        return false;
    }

    bool isconso(char ch) {
        if((ch - 'a') >=0 && (ch - 'a' <=25)) {
            return !isvowel(ch);
        }

        return false;
    }
};