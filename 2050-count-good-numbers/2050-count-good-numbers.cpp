class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans;
        if(n%2 == 0){
            ans = binpow(5, n/2)*binpow(4, n/2);
        } else {
            ans = binpow(5, n/2)*binpow(4, n/2)*5;
        }
        return ans%1000000007;  
    }
    long long binpow(long long a, long long b) {
        int mod = 1e9+7;
        a = a%mod;
        if (b == 0){
            return 1;
        }

        long long res = binpow(a, b / 2)%mod;
        if (b % 2){
            return (res * res * a)%mod;
        }else{
            return (res * res)%mod;
        }
    }
};