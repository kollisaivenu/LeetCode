class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++) {
            ans = min(ans, sum(nums[i]));
        }

        return ans;
    }

    int sum(int a) {
        int sum = 0;
        while(a) {
            int digit = a%10;
            sum += digit;
            a = a/10;
        }

        return sum;
    }
};