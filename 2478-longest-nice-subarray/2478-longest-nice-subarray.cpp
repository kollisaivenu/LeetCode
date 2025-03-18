class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int curr_set_bits = 0;
        int left = 0, right = 0, max_len = 1;

        while(right < nums.size()){

            while((left < right) && ((curr_set_bits & nums[right]) != 0)){
                curr_set_bits = curr_set_bits ^ nums[left];
                left++;
            }

            max_len = max(max_len, right-left+1);
            curr_set_bits = curr_set_bits | nums[right];
            right++;    
        }
        return max_len;
    }
};