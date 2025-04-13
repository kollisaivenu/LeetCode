class Solution {
public:
    int findClosest(int x, int y, int z) {
        int steps1 = abs(x-z);
        int steps2 = abs(y-z);
        
        if(steps1 == steps2){
            return 0;
        } else if(steps1>steps2){
            return 2;
        }
        return 1;
        
    }
};