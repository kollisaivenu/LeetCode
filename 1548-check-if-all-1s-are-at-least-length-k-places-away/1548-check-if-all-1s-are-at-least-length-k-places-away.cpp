class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1) {
                int j=0;
                i=i+1;
                while(i < nums.size() && nums[i] == 0) {
                    j++;
                    i++;
                }

                if(i == nums.size()){
                    return true;
                }

                if(j < k){
                    return false;
                }
                i=i-1;
            }
        }

        return true;
    }
};