class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        for(int i=0;i<colors.size();) {
            if(colors[i] == 'A') {
                int noOfAs = 0;
                while(i < colors.size() && colors[i] == 'A') {
                    i++;
                    noOfAs++;
                }
                alice += max(noOfAs - 2, 0);
            }else if(colors[i] == 'B') {
                int noOfBs = 0;
                while(i < colors.size() && colors[i] == 'B') {
                    i++;
                    noOfBs++;
                }
                bob += max(noOfBs - 2, 0);
            }
        }

        if(alice <= bob){
            return false;
        }
        return true;       
    }
};