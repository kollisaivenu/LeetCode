class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int even = 0, odd = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                even++;
            } else {
                odd++;
            }
        }

        vector<int>ans;
        int i=1,j=1;

        while(i<=even){
            ans.push_back(0);
            i++;
        }

        while(j<=odd){
            ans.push_back(1);
            j++;
        }

        return ans;
        
    }
};