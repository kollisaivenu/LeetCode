class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1, INT_MIN));
        return recur(nums1, nums2, 0, 0, dp);
    }

    int recur(vector<int>&nums1, vector<int>&nums2, int i, int j, vector<vector<int>>&dp) {
        if(i == nums1.size() || j == nums2.size()) {
            return INT_MIN;
        }
        if(dp[i+1][j+1] == INT_MIN) {
            dp[i+1][j+1] = recur(nums1, nums2, i+1, j+1, dp);
        }
        int ans = INT_MIN;
        ans = max(ans, nums1[i]*nums2[j] + max(0, dp[i+1][j+1]));

        if(dp[i+1][j] == INT_MIN) {
            dp[i+1][j] = recur(nums1, nums2, i+1, j, dp);
        }
        ans = max(ans, dp[i+1][j]);
        if(dp[i][j+1] == INT_MIN) {
            dp[i][j+1] = recur(nums1, nums2, i, j+1, dp);
        }

        ans = max(ans, dp[i][j+1]);

        return ans;
    }
};