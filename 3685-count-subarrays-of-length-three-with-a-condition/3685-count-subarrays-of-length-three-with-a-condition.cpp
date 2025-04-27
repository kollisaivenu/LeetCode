class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=2, count = 0;

        for(;i<nums.size();i++){
            if(2*(nums[i-2]+nums[i]) == nums[i-1]){
                count++;
            }
        }

        return count;
        
    }
};