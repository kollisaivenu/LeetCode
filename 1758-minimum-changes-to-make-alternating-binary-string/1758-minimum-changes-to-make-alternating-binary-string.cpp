class Solution {
public:
    int minOperations(string s) {
        int start1 = 0;
        int needsToBe1 = true;
        for(int i=0;i<s.length();i++){
            if(needsToBe1 && s[i] == '1') {
                needsToBe1 = !needsToBe1;
            } else if(!needsToBe1 && s[i] == '0') {
                needsToBe1 = !needsToBe1;
            } else {
                start1++;
                needsToBe1 = !needsToBe1;
            }
        }

        int start0 = 0;
        int needsToBe0 = true;
        for(int i=0;i<s.length();i++){
            if(needsToBe0 && s[i] == '0') {
                needsToBe0 = !needsToBe0;
            } else if(!needsToBe0 && s[i] == '1') {
                needsToBe0 = !needsToBe0;
            } else {
                start0++;
                needsToBe0 = !needsToBe0;
            }
        }
        
        return min(start0, start1);
    }
};