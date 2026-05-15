class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i=0;i<nums.size();i++) {
            vector<int>dg = digits(nums[i]);
            ans.insert(ans.end(), dg.begin(), dg.end());
        }

        return ans;
    }

    vector<int> digits(int n) {
        vector<int>d;
        while(n) {
            int digit = n%10;
            n = n/10;
            d.push_back(digit);
        }

        reverse(d.begin(), d.end());
        return d;
    }
};