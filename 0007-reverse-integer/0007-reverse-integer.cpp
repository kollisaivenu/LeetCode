class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if(x<0){
            if(x > INT_MIN){
                isNeg = true;
                x = abs(x);
            } else {
                return 0;
            }
            
        }
        int reversedX = 0;
        while(x>9){
            int digit = x%10;
            x = x/10;

            reversedX = reversedX*10 + digit;
        }

        if(isNeg){
            if(reversedX > INT_MAX/10){
                return 0;
            } else if(reversedX == INT_MAX/10){
                if(x<=8){
                    reversedX = reversedX*10 + x;
                } else {
                    return 0;
                }
            } else {
                reversedX = reversedX*10 + x;
            }

        } else {
            if(reversedX > INT_MAX/10){
                return 0;
            } else if(reversedX == INT_MAX/10){
                if(x<=7){
                    reversedX = reversedX*10 + x;
                } else {
                    return 0;
                }
            } else {
                reversedX = reversedX*10 + x;
            }
        }

        if(isNeg){
            return -reversedX;
        }

        return reversedX;
        
    }
};