class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int>freq;
        int numOfElements = nums.size();

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans = 0;
        for(int i=0;i<nums.size();){
            if(freq.size() == nums.size()-i){
                break;
            }
            ans++;
            int removeElements = 3;
            while(removeElements && i<nums.size()){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
                removeElements--;
            }
        }
        return ans;
    }
};