class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left;i<=right;i++) {
            int bits = __builtin_popcount(i);
            if(isprime(bits)) {
                ans++;
            }
        }
        return ans;
    }

    bool isprime(int no) {
        int count = 0;
        if(no == 1) {
            return false;
        }
        
        for(int i=2;i*i<=no;i++) {
            if(no%i == 0) {
                count++;
            }
        }

        return count == 0;
    }
};