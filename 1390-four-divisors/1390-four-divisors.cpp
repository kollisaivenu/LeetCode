class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int div = check(nums[i]);

            if(div > 0) {
                ans = ans + 1 + nums[i] + div + nums[i]/div;
            }
        }

        return ans;
        
    }

    int check(int num) {
        int div = 0;
        int count = 2;

        for(int i=2;i<=(int)sqrt(num);i++) {
            if(num%i == 0) {
                if(i == num/i) {
                    count++;
                } else {
                    count += 2;
                    div = i;
                }
            } 
        }

        if(count == 4) {
            return div;
        } else {
            return 0;
        }
    }
};