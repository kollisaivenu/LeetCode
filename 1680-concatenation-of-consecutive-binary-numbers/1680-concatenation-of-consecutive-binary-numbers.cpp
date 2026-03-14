class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int curr = 1;
        while(curr <= n) {
            int bit = 32 - __builtin_clz(curr);
            ans = ((ans << bit) | curr)%1000000007;
            curr++;
        }

        return ans;
    }
};