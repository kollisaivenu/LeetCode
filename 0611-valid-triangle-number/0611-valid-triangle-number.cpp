class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if(nums.size() <= 2){
            return count;
        }
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1 && nums[i] > 0;j++){
                int k = binarySearch(nums, j+1, nums.size()-1, nums[i]+nums[j]);
                
                if(k != -1) {
                    count += (k - j);
                }
            }
        }

        return count;
    }

    int binarySearch(vector<int>&nums, int low, int high, int x){
        int index = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(nums[mid] < x){
                index = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return index;
    }
};