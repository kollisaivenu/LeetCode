class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int i=1;i<=6;i++){
            int top = 0, bottom = 0;
            bool possible = true;
            for(int j=0;j<tops.size();j++){
                if(tops[j] == i && bottoms[j] == i){
                    continue;
                } else if(tops[j] == i){
                    top++;
                } else if(bottoms[j] == i){
                    bottom++;
                } else {
                    possible = false;
                    break;
                }
            }

            if(possible){
                ans = min(ans, min(top, bottom));
            }
        }
        
        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};