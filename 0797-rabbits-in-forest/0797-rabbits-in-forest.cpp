class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>rabbits(1001, 0);
        int totalRabbits = 0;
        for(int i=0;i<answers.size();i++){
            rabbits[answers[i]]++;
        }

        for(int i=0;i<=1000;i++){
            if(rabbits[i]%(i+1) == 0){
                totalRabbits += rabbits[i];
            } else {
                totalRabbits += (i+1)*((rabbits[i]/(i+1))+1);
            }
        }

        return totalRabbits;


    }
};