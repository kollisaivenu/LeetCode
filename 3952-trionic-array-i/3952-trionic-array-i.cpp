class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        for(int p=1;p<nums.size();p++){
            for(int q=p+1;q<nums.size()-1;q++){
                bool isTrionic = true;
                for(int i=1;i<=p;i++){
                    if(nums[i] <= nums[i-1]){
                        isTrionic = false;
                        break;
                    }
                }

                for(int i=p+1;i<=q;i++){
                    if(nums[i] >= nums[i-1]){
                        isTrionic = false;
                        break;
                    }
                }

                for(int i=q+1;i<nums.size();i++){
                    if(nums[i] <= nums[i-1]){
                        isTrionic = false;
                        break;
                    }
                }

                if(isTrionic){
                    return true;
                }
            }
        }
        return false;
    }
};