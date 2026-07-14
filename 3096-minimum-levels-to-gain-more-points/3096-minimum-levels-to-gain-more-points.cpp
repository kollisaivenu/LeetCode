class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum = 0;

        for(int i=0;i<possible.size();i++) {
            if(possible[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }
        }

        int alice = 0;
        for(int i=0;i<possible.size()-1;i++) {
            if(possible[i] == 0) {
                sum += 1;
                alice -= 1;
            } else {
                sum -= 1;
                alice += 1;
            }

            if(alice>sum) {
                return i+1;
            }
        }

        return -1;
        
    }
};