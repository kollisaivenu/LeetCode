class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int low = start, high = start;
        int ans;
        while(low >= 0 || high < nums.size()) {
            if(low >= 0 && nums[low] == target) {
                ans = abs(low-start);
                break;
            } else if(high < nums.size() && nums[high] == target) {
                ans = abs(high-start);
                break;
            }

            if(low >= 0) {
                low--;
            }

            if(high < nums.size()) {
                high++;
            }
        }
        return ans;
    }
};