class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long>left, right;

        for(int i=0;i<nums.size();i++){
            if(i == 0) { 
                left[nums[i]]++;
                continue;
            }
            right[nums[i]]++;
        }
        long long count = 0;
        for(int i=1;i<nums.size()-1;i++){
            right[nums[i]]--;
            count += left[nums[i]*2]*right[nums[i]*2];
            left[nums[i]]++;
        }

        return count%1000000007;
        
    }
};