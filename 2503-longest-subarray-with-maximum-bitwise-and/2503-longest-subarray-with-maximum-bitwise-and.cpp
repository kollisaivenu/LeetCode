class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = INT_MIN;
        for(int i=0;i<nums.size();i++){
            m = max(m, nums[i]);
        }
        int len = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == m){
                int lenc = 1;
                int j=i+1;
                while(j<nums.size() && nums[j] == m){
                    lenc++;
                    j++;
                }
                i=j-1;
                len = max(len, lenc);
            }
        }
        
        return len;
    }
};