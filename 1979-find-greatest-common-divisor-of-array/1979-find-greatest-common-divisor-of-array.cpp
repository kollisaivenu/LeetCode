class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = std::minmax_element(nums.begin(), nums.end());
        return gcd(*mn, *mx);
    }

    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }

        return gcd(b, a%b);
    }
};