class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(isBalanced(i)){
                return i;
            }
        }

        return -1;
    }

    bool isBalanced(int n){
        vector<int>freq(10);

        while(n>0){
            int digit = n%10;
            freq[digit]++;
            n=n/10;
        }

        for(int i=0;i<=9;i++){
            if(i != freq[i] && freq[i] > 0){
                return false;
            }
        }

        return true;
    }
};