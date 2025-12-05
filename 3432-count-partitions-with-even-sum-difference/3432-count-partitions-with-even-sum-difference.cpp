class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sumRight = 0, sumLeft = 0, ans = 0;

        for(int i=0;i<nums.size();i++){
            sumRight += nums[i];
        }

        for(int i=0;i<nums.size()-1;i++){
            sumLeft += nums[i];
            sumRight -= nums[i];

            if((sumLeft + sumRight)%2 == 0) {
                ans++;
            }
        }

        return ans;
        
    }
};