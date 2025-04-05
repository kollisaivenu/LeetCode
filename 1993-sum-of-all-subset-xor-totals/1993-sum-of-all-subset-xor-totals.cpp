class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        xorSum(sum, 0, nums, 0);
        return sum;
    }

    void xorSum(int &sum, int index, vector<int>&nums, int currSum){
        if(index == nums.size()){
            sum += currSum;
            return;
        }

        xorSum(sum, index+1, nums, currSum);
        xorSum(sum, index+1, nums, currSum ^ nums[index]);
    }
};