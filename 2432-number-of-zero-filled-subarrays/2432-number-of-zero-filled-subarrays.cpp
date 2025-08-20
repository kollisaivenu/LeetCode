class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        long long prev = 0;
        for(int i=0;i<nums.size();i++){
            long long curr = 0;
            if(nums[i] == 0){
                if(i == 0){
                    curr = 1;
                } else {
                    curr = 1 + prev;
                }
            }
            sum += curr;
            prev = curr;
        }

        return sum;
    }
};