class Solution {
public:
    long long flowerGame(int n, int m) {
        long long noOfEvenNumbersN = 0, noOfOddNumbersN = 0, noOfEvenNumbersM = 0, noOfOddNumbersM = 0;

        if(n%2 == 0){
            noOfEvenNumbersN = n/2;
            noOfOddNumbersN = n/2;
        } else {
            noOfEvenNumbersN = (n-1)/2;
            noOfOddNumbersN = (n+1)/2;
        }

        if(m%2 == 0){
            noOfEvenNumbersM = m/2;
            noOfOddNumbersM = m/2;
        } else {
            noOfEvenNumbersM = (m-1)/2;
            noOfOddNumbersM = (m+1)/2;
        }

        return noOfOddNumbersN*noOfEvenNumbersM + noOfEvenNumbersN*noOfOddNumbersM;



    }
};