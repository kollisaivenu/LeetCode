class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int>largest(nums.size());
        vector<int>smallest(nums.size());

        long long ans;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i == nums.size()-1){
                largest[i] = nums[i];
                smallest[i] = nums[i];
            } else {
                largest[i] = max(nums[i], largest[i+1]);
                smallest[i] = min(nums[i], smallest[i+1]);
            }
        }

        for(int i=0;i<=nums.size()-m;i++){
            if(i == 0){
                ans = max((long long)nums[i]*largest[i+m-1], (long long)nums[i]*smallest[i+m-1]);
            } else {
                ans = max(ans, (long long)nums[i]*largest[i+m-1]);
                ans = max(ans, (long long)nums[i]*smallest[i+m-1]);
            }
            
        }

        return ans;
    }
};