class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for(int i=0;i<nums.size();){
            if(nums[i] == 0 && i > left){
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
                left++;
            } else if(nums[i] == 2 && i < right) {
                int temp = nums[right];
                nums[right] = nums[i];
                nums[i] = temp;
                right--;
            } else {
                i++;
            }
        }
    }
};