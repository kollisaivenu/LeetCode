class Solution {
public:
    bool hasAlternatingBits(int n) {
        int start = n & 1;
        n = n>>1;

        while(n) {
            if((n & 1) == 1 - start) {
                n = n>>1;
                start = 1 - start;
            } else {
                return false;
            }
        }

        return true;
    }

    
};