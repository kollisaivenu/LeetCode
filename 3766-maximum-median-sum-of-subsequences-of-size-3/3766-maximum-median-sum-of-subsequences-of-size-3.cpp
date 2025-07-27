class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        long long sum = 0;
        
        while(j>i+1){
            sum += nums[j-1];
            j=j-2;
            i++;
        }

        return sum;
        
    }
};