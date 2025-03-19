class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0;
        bool flipped = false;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0 && !flipped){
                flips++;
                flipped = true;
            } else if(nums[i] == 1 && flipped){
                flips++;
                flipped = false;
            }
        }
        return flips;
        
    }
};