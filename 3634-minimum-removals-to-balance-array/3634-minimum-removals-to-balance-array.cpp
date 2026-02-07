class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            int ind = get_index(nums, i, k);
            ans = min(ans, i + (int)nums.size()-ind-1);
        }

        return ans;
    }

    int get_index(vector<int>&nums, int i, int k) {
        int low = i, high = nums.size()-1;
        int ans = -1;
        while(low<=high) {
            int mid = (high-low)/2 + low;

            if((long long)nums[mid] <= (long long)nums[i]*k) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ans;
    }
};