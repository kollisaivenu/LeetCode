class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int noOfBottlesDrunk = numBottles;
        int noOfBottlesEmpty = numBottles;

        while(noOfBottlesEmpty >= numExchange) {
            noOfBottlesEmpty = noOfBottlesEmpty - numExchange + 1;
            numExchange++;
            noOfBottlesDrunk++;
        }
        
        return noOfBottlesDrunk;
    }
};