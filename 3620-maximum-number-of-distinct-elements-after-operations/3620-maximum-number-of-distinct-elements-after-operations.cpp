class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int distinctNum = 0, prevMax = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int lowerBound = nums[i] - k;
            int upperBound = nums[i] + k;

            if(prevMax < lowerBound){
                prevMax = lowerBound;
                distinctNum++;
            } else if(prevMax < upperBound){
                prevMax++;
                distinctNum++;
            }
        }

        return distinctNum;
    }
};