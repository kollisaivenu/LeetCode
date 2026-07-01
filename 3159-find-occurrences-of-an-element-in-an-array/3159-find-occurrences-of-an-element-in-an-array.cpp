class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occ;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == x) {
                occ.push_back(i);
            }
        }

        vector<int>ans(queries.size(), -1);

        for(int i=0;i<queries.size();i++) {
            if(queries[i] <= occ.size()) {
                ans[i] = occ[queries[i]-1];
            }
        }

        return ans;
        
    }
};