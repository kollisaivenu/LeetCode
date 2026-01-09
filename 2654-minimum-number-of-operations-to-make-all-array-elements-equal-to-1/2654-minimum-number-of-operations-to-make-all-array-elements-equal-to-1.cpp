class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int nums1 = 0;
        int g = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                nums1++;
            }

            g = gcd(g, nums[i]);
        }

        if(nums1 > 0){
            return n - nums1;
        }

        if(g > 1) {
            return -1;
        }

        int min_len = n;

        for(int i=0;i<n;i++) {
            int g = 0;
            for(int j=i;j<n;j++){
                g = gcd(g, nums[j]);

                if(g == 1){
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        return min_len + n -2;
    }
};