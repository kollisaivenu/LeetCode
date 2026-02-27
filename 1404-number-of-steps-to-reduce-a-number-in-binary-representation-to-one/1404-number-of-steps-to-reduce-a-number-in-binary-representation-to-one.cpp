class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while(!isOne(s)) {
            if(isOdd(s)) {
                updateOdd(s);
            } else {
                updateEven(s);
            }
            count++;
        }

        return count;
        
    }

    bool isOne(string &s) {
        for(int i=0;i<s.length()-1;i++) {
            if(s[i] == '1') {
                return false;
            }
        }

        return s[s.length()-1] == '1';
    }

    bool isOdd(string &s) {
        return s[s.length()-1] == '1';
    }

    void updateOdd(string &s) {
        int carry = 1;
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == '1' && carry == 1) {
                s[i] = '0';
            } else if(s[i] == '0' && carry == 1) {
                s[i] = '1';
                carry = 0;
            }
        }

        if(carry == 1) {
            s.insert(0, "1");
        }
    }

    void updateEven(string &s) {
        for(int i=s.length()-2;i>=0;i--) {
            s[i+1] = s[i];
        }

        s[0] = '0';
    }
};