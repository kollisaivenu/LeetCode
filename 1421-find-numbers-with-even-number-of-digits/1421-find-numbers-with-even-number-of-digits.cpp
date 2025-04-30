class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int i=0;i<nums.size();i++){
            if(isEvenNumOfDigits(nums[i])){
                count++;
            }
        }

        return count;
        
    }

    int isEvenNumOfDigits(int no){
        int digits = 0;
        while(no){
            digits++;
            no = no/10;
        }

        return digits%2 == 0;
    }
};