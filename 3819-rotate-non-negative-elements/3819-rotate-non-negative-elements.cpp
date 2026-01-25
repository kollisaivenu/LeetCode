class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int c = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= 0) {
                c++;
            }
        }

        vector<int>nneg(c, 0);
        int ind = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= 0) {
                nneg[(ind - k%c + c)%c] = nums[i];
                ind++;
            }
        }
        ind = 0;
        vector<int>ans(nums.size(), 0);
        for(int i=0;i<nums.size();i++) {
            if(nums[i] >= 0) {
                ans[i] = nneg[ind];
                ind++;
            } else {
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};