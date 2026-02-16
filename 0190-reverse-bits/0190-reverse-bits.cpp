class Solution {
public:
    int reverseBits(int n) {
        vector<bool>bits(32, false);

        for(int i=0;i<32;i++) {
            if(n & 1) {
                //cout<<i<<" \n";
                bits[31-i] = true;
            }
            n=n>>1;
        }

        int ans = 0;
        for(int i=31;i>=0;i--) {
            if(bits[i]) {
                ans = ans + pow(2, i);
            }
        }

        return ans;
    }
};