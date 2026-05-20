class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>vis;
        vector<int>array;
        sort(nums.begin(), nums.end());
        subset(ans, vis, nums, 0, array);
        return ans;
    }

    void subset(vector<vector<int>>&ans, set<vector<int>>&vis, vector<int>&nums, int i, vector<int>array) {
        if(i == nums.size()) {
            if(!vis.contains(array)) {
                ans.push_back(array);
                vis.insert(array);
            }
            return;
        }

        subset(ans, vis, nums, i+1, array);
        array.push_back(nums[i]);
        subset(ans, vis, nums, i+1, array);        
    }
};