class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            for(int j=-k;j<=k;j++){
                if(i+j >= 0 && i+j < nums.size() && nums[i+j] == key){
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};