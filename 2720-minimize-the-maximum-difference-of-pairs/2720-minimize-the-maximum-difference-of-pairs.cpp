class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size()-1]-nums[0], ans;
    
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isValid(mid, p, nums)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    bool isValid(int diff, int pairs, vector<int>&nums){
        int count = 0;
        for(int i=0;i<nums.size()-1;){
            if(abs(nums[i] - nums[i+1]) <= diff) {
                count++;
                i=i+2;
            } else {
                i++;
            }
        }

        return count >= pairs;
    }
};