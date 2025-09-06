class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1 = num1;
        long long n2 = num2;
        int ops = 0;
        while(true){
            n1 = n1 - n2;
            ops++;

            if(ops > n1){
                return -1;
            }

            if(noOfBits(n1) <= ops){
                return ops;
            }
        }

        return -1;
    }

    int noOfBits(long long no){
        long long count = 0;
        while(no){
            if(no & 1){
                count++;
            }
            no = no>>1;
        }

        return count;
    }
};