class Solution {
public:
    int maxOperations(string s) {
        int ops = 0, ones = 0;
        for(int i=0;i<s.length();){
            if(s[i] == '1') {
                ones++;
                i++;
            } else {
                while(i<s.length() && s[i] == '0'){
                    i++;
                }
                ops += ones;
            }
        }

        return ops;    
    }
};