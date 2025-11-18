class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();){
            if(i == bits.size()-1 && bits[i] == 0){
                return true;
            } else if(i == bits.size()-2 && bits[i] == 1) {
                return false;
            } else if(bits[i] == 1) {
                i=i+2;
            } else if(bits[i] == 0){
                i=i+1;
            }
        }

        return false;
        
    }
};