class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int empty = 0, x=0;
        for(int i=0;i<moves.size();i++) {
            if(moves[i] == 'L') {
                x--;
            } else if(moves[i] == 'R') {
                x++;
            } else {
                empty++;
            }
        }

        return abs(x) + empty;
    }
};