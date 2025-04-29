class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0, j=0, maxNum = INT_MIN, noOfMaxNum = 0;
        long long count = 0, totalSubarrays = (nums.size())*(nums.size()+1)/2;

        for(int i=0;i<nums.size();i++){
            maxNum = max(maxNum, nums[i]);
        }

        while(j<nums.size()){
            if(nums[j] == maxNum){
                noOfMaxNum++;
            }
            if(noOfMaxNum == k){
                while(noOfMaxNum == k){
                    if(nums[i] == maxNum){
                        noOfMaxNum--;
                    }
                    i++;
                }
            }
            count += j-i+1;
            j++;
        }

        return totalSubarrays - count;
        
        
    }
};