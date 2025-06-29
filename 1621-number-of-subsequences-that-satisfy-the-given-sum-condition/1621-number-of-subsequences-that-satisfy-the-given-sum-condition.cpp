class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod_num = 1000000007;
        int ans = 0;
        vector<int> fastExp(nums.size() + 1);
        fastExp[0] = 1;

        for (int i = 1; i <= nums.size(); ++i) {
            fastExp[i] = (fastExp[i - 1] * 2) % mod_num;
        }
        
        for(int i=0;i<nums.size();i++){
            int end = lookup(nums, i, target);
            if(end != -1){
                ans = (ans + fastExp[end-i])%mod_num;
            }
            
        }
        return ans;
    }

    int lookup(vector<int>& nums, int index, int target){
        int low = index, high = nums.size()-1;
        int i = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]+nums[index] <= target){
                i = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return i;
    }
};