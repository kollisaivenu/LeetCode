class Solution {
public:
    int maxProduct(int n) {
        vector<int>f(10, 0);
        while(n) {
            int dig = n%10;
            f[dig]++;
            n = n/10;
        }   
        int a = -1, b = -1;
        bool flag = false;
        for(int i=9;i>=0;i--) {
            while(f[i]) {
                if(a == -1) {
                    a = i;
                    f[i]--;
                } else {
                    b = i;
                    f[i]--;
                    flag = true;
                    break;
                }
            }

            if(flag) {
                break;
            }
            
        }

        return a*b;
    }
};