class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>temp;
        for(int i=1;i<nums.size();i++) {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        return nums[0] + temp[0] + temp[1];
    }
};