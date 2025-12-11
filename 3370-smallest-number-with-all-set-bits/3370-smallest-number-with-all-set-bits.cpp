class Solution {
public:
    int smallestNumber(int n) {
        for(int i=n;;i++){
            if(isAllSet(i)) {
                return i;
            }
        }
        
        return -1;
    }

    bool isAllSet(int i) {
        while(i>0){
            if((i & 1) == 0) {
                return false;
            } 
            i=i>>1;
        }

        return true;
    }
};