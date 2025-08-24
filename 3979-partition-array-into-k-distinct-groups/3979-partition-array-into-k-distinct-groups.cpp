class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int, int>freq;
        if(nums.size()%k !=0){
            return false;
        } 
        int numOfGroups = nums.size()/k;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if(it->second > numOfGroups){
                return false;
            }
        }

        return true;
        
    }
};