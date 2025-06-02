class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>leftCandies(ratings.size(), 0);
        vector<int>rightCandies(ratings.size(), 0);
        leftCandies[0] = 1;
        rightCandies[ratings.size()-1] = 1;

        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                leftCandies[i] = leftCandies[i-1]+1;
            } else {
                leftCandies[i] = 1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rightCandies[i] = rightCandies[i+1]+1;
            } else {
                rightCandies[i] = 1;
            }
        }

        int sumOfCandies = 0;

        for(int i=0;i<ratings.size();i++){
            sumOfCandies += max(leftCandies[i], rightCandies[i]);
        }

        return sumOfCandies;




        
    }
};