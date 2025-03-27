class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominantElement = -1, votes = 0, numberOfDominantElement = 0;
        for(int i=0;i<nums.size();i++){
            if(votes == 0){
                dominantElement = nums[i];
                votes++;
            } else {
                if(dominantElement == nums[i]){
                    votes++;
                } else {
                    votes--;
                }
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] == dominantElement){
                numberOfDominantElement++;
            }
        }
        int dominantElementsOnLeft = 0, dominantElementsOnRight = numberOfDominantElement;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == dominantElement){
                dominantElementsOnLeft++;
                dominantElementsOnRight--;

            }

            int elementsToTheLeft = (i - 0 + 1), elementsToTheRight = (nums.size() - i - 1);

            if(dominantElementsOnLeft > elementsToTheLeft/2 && dominantElementsOnRight > elementsToTheRight/2){
                return i;
            }
            
        }
        return -1;
    }
};