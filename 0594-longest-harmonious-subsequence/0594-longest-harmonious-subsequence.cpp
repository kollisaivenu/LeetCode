class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int>m;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            if(m[nums[i]+1] != 0){
                ans = max(ans, m[nums[i]+1] + m[nums[i]]);
            }
        }
        return ans;
    }
};