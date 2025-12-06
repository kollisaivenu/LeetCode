class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        priority_queue<int, std::vector<int>, std::greater<int>> mod1, mod2;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(nums[i]%3 == 1) {
                mod1.push(nums[i]);
            }

            if(nums[i]%3 == 2) {
                mod2.push(nums[i]);
            }
        }
        int firstSmallestMod1 = 0, secondSmallestMod1 = 0, firstSmallestMod2 = 0, secondSmallestMod2 = 0;

        if(!mod1.empty()) {
            firstSmallestMod1 = mod1.top();
            mod1.pop();
        }

        if(!mod1.empty()) {
            secondSmallestMod1 = mod1.top();
            mod1.pop();
        }

        if(!mod2.empty()) {
            firstSmallestMod2 = mod2.top();
            mod2.pop();
        }

        if(!mod2.empty()) {
            secondSmallestMod2 = mod2.top();
            mod2.pop();
        }

        int ans;
        if(sum%3 == 0){
            ans = sum;
        } else if(sum%3 == 1) {
            if(firstSmallestMod1 == 0) {
                ans = sum - firstSmallestMod2 - secondSmallestMod2;
            } else if(secondSmallestMod2 == 0) {
                ans = sum - firstSmallestMod1;
            } else if(secondSmallestMod2 > 0){
                ans = sum - min(firstSmallestMod1, firstSmallestMod2 + secondSmallestMod2);
            }
        } else {
            if(firstSmallestMod2 == 0) {
                ans = sum - firstSmallestMod1 - secondSmallestMod1;
            } else if(secondSmallestMod1 == 0) {
                ans = sum - firstSmallestMod2;
            } else if(secondSmallestMod1 > 0){
                ans = sum - min(firstSmallestMod2, firstSmallestMod1 + secondSmallestMod1);
            }
        }

        return ans;
    }
};