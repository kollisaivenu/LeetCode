class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool possible = false;
        for(int i=0;i<triplets.size();i++) {
            if(triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                possible = true;
                break;
            }
        }

        if(!possible) {
            return false;
        }

        possible = false;        
        for(int i=0;i<triplets.size();i++) {
            if(triplets[i][1] == target[1] && triplets[i][0] <= target[0] && triplets[i][2] <= target[2]) {
                possible = true;
                break;
            }
        }

        if(!possible) {
            return false;
        }

        possible = false;        
        for(int i=0;i<triplets.size();i++) {
            if(triplets[i][2] == target[2] && triplets[i][0] <= target[0] && triplets[i][1] <= target[1]) {
                possible = true;
                break;
            }
        }

        return possible;

        
    }
};