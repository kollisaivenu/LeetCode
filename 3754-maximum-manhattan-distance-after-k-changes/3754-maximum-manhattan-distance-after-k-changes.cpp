class Solution {
public:
    int maxDistance(string s, int k) {
        vector<char>northSouth{'N', 'S'};
        vector<char>eastWest{'E', 'W'};
        int currMaxDist = INT_MIN;

        for(int l=0;l<northSouth.size();l++){
            for(int m=0;m<eastWest.size();m++){
                int maxDist = 0, change = 0;
                for(int n=0;n<s.length();n++){
                    if(s[n] == northSouth[l] || s[n] == eastWest[m]){
                        maxDist++;
                    } else if(change < k){
                        maxDist++;
                        change++;
                    } else {
                        maxDist--;
                    }
                    currMaxDist = max(currMaxDist, maxDist);
                }
                
            }
        }

        return currMaxDist;
        
    }
};