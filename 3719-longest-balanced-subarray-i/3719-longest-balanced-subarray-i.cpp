class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            int odd = 0, even = 0;
            map<int, bool>ispresent;
            for(int j=i;j<nums.size();j++) {
                if(nums[j]%2 == 0 && !ispresent[nums[j]]) {
                    ispresent[nums[j]] = true;
                    even++;
                } else if(nums[j]%2 == 1 && !ispresent[nums[j]]) {
                    ispresent[nums[j]] = true;
                    odd++;
                } 

                if(odd == even) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};