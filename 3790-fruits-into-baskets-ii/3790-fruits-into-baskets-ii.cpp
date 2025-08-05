class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int totalTypes = fruits.size();
        
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i] <= baskets[j]){
                    totalTypes--;
                    baskets[j] = -1;
                    break;
                }
            }
        }
        return totalTypes;
    }
};