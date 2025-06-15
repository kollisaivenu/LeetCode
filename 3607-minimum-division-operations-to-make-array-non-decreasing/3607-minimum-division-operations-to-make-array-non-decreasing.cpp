class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                int transformedNum = transform(nums[i]);

                if(transformedNum == nums[i] || transformedNum > nums[i+1]){
                    return -1;
                }

                nums[i] = transformedNum;
                ops++;
            }
        }

        return ops;
        
    }

    int transform(int n){
        int i=2;
        for(;i<=n;i++){
            if(n%i == 0){
                break;
            }
        }

        return i;
    }
};