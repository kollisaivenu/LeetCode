class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);

        for(int i=0;i<nums.size();i++) {
            ans[i] = getNum(nums[i]);
        }
        
        return ans;
    }

    int getNum(int n) {
        for(int i=0;i<=n;i++) {
            if((i | (i+1)) == n) {
                return i;
            }
        }

        return -1;
    }
};