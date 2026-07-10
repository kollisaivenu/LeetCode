class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0;i<nums1.size();i++) {
            int ind = getIndexOfLargestElement(i, nums1[i], nums2);

            if(ind != -1) {
                ans = max(ans, ind-i);
            }
        }

        return ans;
    }

    int getIndexOfLargestElement(int low, int num, vector<int>&nums) {
        int high = nums.size()-1;
        int ind = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;

            if(nums[mid] >= num) {
                ind = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ind;
    }
};