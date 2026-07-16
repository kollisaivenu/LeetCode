class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGcd(nums.size());
        int mx = INT_MIN;

        for(int i=0;i<nums.size();i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = (gcd(nums[i], mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        for(int i=0,j=prefixGcd.size()-1;i<j;i++,j--) {
            ans = ans + gcd(prefixGcd[i], prefixGcd[j]);
        }

        return ans;
    }

    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }

        return gcd(b, a%b);
    }
};