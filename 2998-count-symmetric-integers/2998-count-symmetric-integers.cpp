class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        
        for(int i=low;i<=high;i++){
            if(isSymmetric(i)){
                count++;
            }
        }

        return count;
    }

    bool isSymmetric(int no){
        int noOfDigits = log10(no) + 1;

        if(noOfDigits%2 == 1){
            return false;
        }
        int digitsConsidered = 0, sum1 = 0, sum2 = 0;
        while(no){
            int digit = no%10;
            digitsConsidered++;
            if(digitsConsidered <= noOfDigits/2){
                sum1 += digit;
            } else {
                sum2 += digit;
            }
            no = no/10;
        }

        if(sum1 == sum2){
            return true;
        }
        return false;
    }
};