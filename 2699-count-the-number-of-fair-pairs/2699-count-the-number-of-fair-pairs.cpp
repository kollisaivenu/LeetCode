class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-1;i++){
            int minNumIndex = getMinIndexToAdd(nums[i], i+1, lower, nums);
            int maxNumIndex = getMaxIndexToAdd(nums[i], i+1, upper, nums);

            if(minNumIndex != -1 && maxNumIndex != -1 && minNumIndex <= maxNumIndex){
                count += (maxNumIndex - minNumIndex + 1);
            }
        }

        return count;
    }

    int getMinIndexToAdd(int num, int index, int lower, vector<int>&v){
        int low = index, high = v.size()-1, ans = -1;

        while(low<=high){
            int mid = (high+low)/2;

            if(num + v[mid] >= lower){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    int getMaxIndexToAdd(int num, int index, int upper, vector<int>&v){
        int low = index, high = v.size()-1, ans = -1;

        while(low<=high){
            int mid = (high+low)/2;

            if(num + v[mid] <= upper){
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
};