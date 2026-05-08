class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(check(i)){
                ans++;
            }
        }

        return ans;
    }

    bool check(int n) {
        int same = 0, rev = 0;
        while(n) {
            int digit = n%10;
            if(digit == 0 || digit == 1 || digit == 8) {
                same++;
                rev++;
            } else if(digit == 6 || digit == 9 || digit == 2 || digit == 5) {
                rev++;
            } else {
                return false;
            }
            n=n/10;
        }

        if(same == rev) {
            return false;
        }

        return true;
    }
};