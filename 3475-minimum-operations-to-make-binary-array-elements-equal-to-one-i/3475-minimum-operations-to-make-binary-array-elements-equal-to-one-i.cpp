class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0;

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == 0){
                flips++;
                int k = 0;
                while(k<3){
                    if(nums[i+k] == 0){
                        nums[i+k] = 1;
                    } else {
                        nums[i+k] = 0;
                    }
                    k++;
                }
            }
        }

        for(int i = nums.size()-3;i<nums.size();i++){
            if(nums[i] == 0){
                return -1;
            }
        }
        return flips;
        
    }
};