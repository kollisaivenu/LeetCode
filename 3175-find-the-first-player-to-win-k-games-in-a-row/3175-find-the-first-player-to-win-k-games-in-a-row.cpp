class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int winner = 0;
        int wins = 0;

        if(k > skills.size()) {
            int winner = 0;
            for(int i=1;i<skills.size();i++) {
                if(skills[winner] < skills[i]) {
                    winner = i;
                }
            }

            return winner;
        }

        for(int i=1;i<skills.size();i=(i+1)%skills.size()) {
            if(winner == i) {
                continue;
            }

            if(skills[winner] > skills[i]) {
                wins++;

                if(wins == k) {
                    return winner;
                }
            } else {
                winner = i;
                wins = 1;

                if(wins == k) {
                    return winner;
                }
            }
        }

        return -1;
    }
};