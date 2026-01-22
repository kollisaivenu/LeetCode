class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        vector<int>temp = nums;
        while(true) {
            if(is_valid(temp)) {
                return ops;
            } 
            ops++;
            int m = temp[0] + temp[1], ind = 1;
            vector<int>new_temp;
            for(int i=2;i<temp.size();i++) {
                if(temp[i] + temp[i-1] < m) {
                    ind = i;
                    m = temp[i] + temp[i-1];
                }
            }

            for(int i=0;i<temp.size();) {
                if(i+1 == ind) {
                    new_temp.push_back(temp[i] + temp[i+1]);
                    i = ind+1;
                } else {
                    new_temp.push_back(temp[i]);
                    i++;
                }
            }

            temp = new_temp;
        }
    }

    bool is_valid(vector<int>&nums) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<nums[i-1]) {
                return false;
            }
        }

        return true;
    }
};