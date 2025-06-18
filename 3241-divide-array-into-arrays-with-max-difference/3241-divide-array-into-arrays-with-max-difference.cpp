class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i=i+3){
            vector<int>group;

            for(int j=0;j<3;j++){
                group.push_back(nums[i+j]);
            }
                
            if(group[2]-group[0] > k){
                return vector<vector<int>>();
            }

            ans.push_back(group);  
        }

        return ans;
        
    }
};