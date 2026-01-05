class Solution {
public:
    int countPrimes(int n) {
        if(n == 1 || n == 0){
            return 0;
        }
        
        vector<bool>primes(n+1, true);
        for(int i=2;i<=n;i++) {
            if(primes[i]) {
                for(int j=2*i;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }
        int ans;
        for(int i=2;i<n;i++){
            if(primes[i]){
                ans++;
            }
        }

        return ans;
    }
};