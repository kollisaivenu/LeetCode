class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini = complexity[0], MOD = 1000000007;

        for(int i=1;i<complexity.size();i++){
            if(mini>=complexity[i]){
                return 0;
            }
        }

        int n = complexity.size()-1;

        long long fact = 1;

        for(int i=1;i<=n;i++){
            fact = ((fact%MOD)*(i%MOD))%MOD;
        }

        return fact%MOD;
    }
};