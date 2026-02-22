class Solution {
public:
    int binaryGap(int n) {
        int last1 = -1, i=0, ans = 0;

        while(n) {
            if(n & 1) {
                if(last1 == -1) {
                    last1 = i;
                } else {
                    ans = max(ans, i - last1);
                    last1 = i;
                }
            }
            i++;
            n = n>>1;
        }

        return ans;
    }
};