class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>ans = nums;

        while(ans.size() > 1) {
            for(int i=0;i<ans.size()-1;i++){
                ans[i] = (ans[i] + ans[i+1])%10;
            }

            ans.resize(ans.size()-1);
        }

        return ans[0];
        
    }
};