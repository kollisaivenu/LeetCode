class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return isPossible(nums, 0, 1, 1, target);
    }

    bool isPossible(vector<int>&nums, int index, __int128 subset1, __int128 subset2, long long target){
        if(nums.size() == index){
            if(subset1 == subset2 && target == subset1){
                return true;
            } else {
                return false;
            }
        }

        
        return isPossible(nums, index+1, subset1*nums[index], subset2, target) || isPossible(nums, index+1, subset1, subset2*nums[index], target);
    }
};