class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int allOdds = 0, allEvens = 0, evenOdds = 0, oddEvens = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                allEvens++;
            } else {
                allOdds++;
            }
        }

        bool needEven = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0 && needEven){
                evenOdds++;
                needEven = false;
            } else if(nums[i]%2 == 1 && !needEven){
                evenOdds++;
                needEven = true;
            }
        }

        bool needOdd = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 1 && needOdd){
                oddEvens++;
                needOdd = false;
            } else if(nums[i]%2 == 0 && !needOdd){
                oddEvens++;
                needOdd = true;
            }
        }

        return max(allEvens, max(allOdds, max(evenOdds, oddEvens)));
    }
};