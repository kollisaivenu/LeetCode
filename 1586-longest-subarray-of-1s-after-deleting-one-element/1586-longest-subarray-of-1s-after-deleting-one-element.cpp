class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        if(nums.size() == 1 || nums.size() == 0){
            return 0;
        }
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == 1){
                left[i] = left[i-1]+1;
            } else {
                left[i] = 0;
            }
        }

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] == 1){
                right[i] = right[i+1]+1;
            } else {
                right[i] = 0;
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i<nums.size();i++){
            if(i == 0){
                ans = max(ans, right[i+1]);
            } else if(i == nums.size() - 1){
                ans = max(ans, left[i-1]);
            } else {
                ans = max(ans, left[i-1] + right[i+1]);
            }
        }
        return ans;
    }
};