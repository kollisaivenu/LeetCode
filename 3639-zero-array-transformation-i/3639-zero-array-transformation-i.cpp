class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>decrements(nums.size(), 0);

        for(int i=0;i<queries.size();i++){
            decrements[queries[i][0]] += -1;

            if(queries[i][1]+1 < nums.size()){
                decrements[queries[i][1]+1] += 1;
            }
        }

        for(int i=1;i<nums.size();i++){
            decrements[i] = decrements[i] + decrements[i-1];
        }

        for(int i=0;i<nums.size();i++){
            if(decrements[i]+nums[i]>0){
                return false;
            }
        }

        return true;
    }
};