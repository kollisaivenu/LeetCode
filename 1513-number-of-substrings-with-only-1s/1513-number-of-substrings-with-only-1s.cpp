class Solution {
public:
    int numSub(string s) {
        long long len = 0, ans = 0;
        for(char ch: s) {
            if(ch == '1') {
                len++;
            } else {
                ans += len*(len+1)/2;
                len = 0;
            }
        }

        ans += len*(len+1)/2;
        return ans%1000000007;
    }
};