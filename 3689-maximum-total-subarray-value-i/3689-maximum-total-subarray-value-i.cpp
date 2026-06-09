class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min_num = LLONG_MAX;
        long long max_num = LLONG_MIN;

        for(int i=0;i<nums.size();i++) {
            min_num = min(min_num, (long long)nums[i]);
            max_num = max(max_num, (long long)nums[i]);
        }

        return k*(max_num - min_num);
        
    }
};