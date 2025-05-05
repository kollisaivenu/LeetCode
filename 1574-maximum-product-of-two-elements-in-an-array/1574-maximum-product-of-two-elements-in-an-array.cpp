class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size() - 1;

        return (nums[len]-1)*(nums[len-1]-1);
    }
};