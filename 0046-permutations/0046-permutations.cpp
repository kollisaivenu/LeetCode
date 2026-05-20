class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>array;
        vector<bool>vis(nums.size(), false);
        dfs(nums, array, ans, vis);
        return ans;
    }

    void dfs(vector<int>&nums, vector<int>array, vector<vector<int>>&ans, vector<bool>&vis) {
        if(array.size() == nums.size()) {
            ans.push_back(array);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!vis[i]) {
                array.push_back(nums[i]);
                vis[i] = true;
                dfs(nums, array, ans, vis);
                vis[i] = false;
                array.pop_back();
            }
        }
    }
};