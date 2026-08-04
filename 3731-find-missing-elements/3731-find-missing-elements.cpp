class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int>ans;
        int no = nums[0];
        for(int i=0;i<nums.size();) {
            if(nums[i] == no) {
                i++;
            } else {
                ans.push_back(no);
            }
            no++;
        }

        return ans;
    }
};