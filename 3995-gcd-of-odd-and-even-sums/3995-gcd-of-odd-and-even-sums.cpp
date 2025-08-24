class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        
        for(int i=1,j=1,k=2;i<=n;i++,j=j+2,k=k+2){
            sumOdd += j;
            sumEven += k;
        }

        int maxPossibleGcd = min(sumOdd, sumEven);
        int ans;
        for(int i=maxPossibleGcd;i>=1;i--){
            if((sumOdd%i == 0) && (sumEven%i == 0)){
                ans = i;
                break;
            }
        }

        return ans;

        
    }
};