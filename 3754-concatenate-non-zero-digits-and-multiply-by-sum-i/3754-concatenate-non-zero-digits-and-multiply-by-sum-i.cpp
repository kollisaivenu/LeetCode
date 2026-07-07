class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int sum = 0;
        int mult = 1;
        while(n > 0) {
            int digit = n%10;
            n = n/10;

            if(digit > 0) {
                sum += digit;
                ans = ans + mult*digit;
                mult = mult*10;
            }
        }

        return ans*sum;
    }
};