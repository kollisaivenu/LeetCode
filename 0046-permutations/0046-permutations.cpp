class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>perm;
        vector<vector<int>>ans;
        vector<bool>vis(nums.size(), false);
        backtrack(nums, perm, vis, ans);

        return ans;
        
    }

    void backtrack(vector<int>&nums, vector<int>&perm, vector<bool>&vis, vector<vector<int>>&ans) {
        if(perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!vis[i]) {
                vis[i] = true;
                perm.push_back(nums[i]);
                backtrack(nums, perm, vis, ans);
                vis[i] = false;
                perm.pop_back();
            }
        }

    }
};