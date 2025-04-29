class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0, j=0, maxNum = INT_MIN, noOfMaxNum = 0;
        //15 - 1 - 2 - 3  = 6
        long long count = 0;

        for(int i=0;i<nums.size();i++){
            maxNum = max(maxNum, nums[i]);
        }

        while(j<nums.size()){
            if(nums[j] == maxNum){
                noOfMaxNum++;
            }
            if(noOfMaxNum == k){
                while(noOfMaxNum != k-1){
                    if(nums[i] == maxNum){
                        noOfMaxNum--;
                    }
                    i++;
                }
            }
            if(noOfMaxNum < k){
                count += j-i+1;
            }
            j++;
        }

        return (nums.size())*(nums.size()+1)/2 - count;
        
        
    }
};