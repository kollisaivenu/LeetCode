class Solution {
public:
    int totalMoney(int n) {
        int monday = 0;
        int total = 0;
        for(int i=0;i<n;i++){
            if(i%7 == 0){
                monday++;
            }
            total = total + (monday + (i%7));
        }

        return total;
    }
};