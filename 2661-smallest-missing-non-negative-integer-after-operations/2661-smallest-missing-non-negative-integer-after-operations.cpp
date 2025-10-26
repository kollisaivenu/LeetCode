class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>freq(value, 0);
        vector<bool>isPresent(nums.size(), false);
        for(int i=0;i<nums.size();i++) {
            int mod = (nums[i]%value+value)%value;
            if(mod + value*freq[mod] < nums.size()){
                isPresent[mod + value*freq[mod]] = true;
            }
            
            freq[mod]++;
        }
    
        int ans = nums.size();
        for(int i=0;i<nums.size();i++) {
            if(!isPresent[i]){
                ans = i;
                break;
            }
        }

        return ans;
    }
};