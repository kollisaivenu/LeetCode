class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int currmax = weight[0];
        int shipments = 0;

        for(int i=1;i<weight.size();i++){
            if(weight[i] < currmax){
                shipments++;
                if(i+1 < weight.size()){
                    currmax = weight[i+1];
                } else {
                    break;
                }
            } else {
                currmax = weight[i];
            }
        }
        return shipments;
        
    }
};