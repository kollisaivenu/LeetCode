class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int>left;
        unordered_map<int, int>right;

        long long count = 0;
        int MOD = 1000000007;

        for(int i=0;i<nums.size();i++){
            right[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){
            right[nums[i]]--;

            if(right[nums[i]] == 0){
                right.erase(nums[i]);
            }

            count = (count + ((long long)left[nums[i]*2]*right[nums[i]*2])%MOD)%MOD;
            left[nums[i]]++;
        }

        return count%MOD;
    }
};