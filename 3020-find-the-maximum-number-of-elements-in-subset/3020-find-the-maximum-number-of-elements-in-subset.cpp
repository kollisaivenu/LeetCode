class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int>freq;

        for(int num : nums) {
            freq[num]++;
        }
        int ans = INT_MIN, count = 0;
        if(freq[1] >= 1) {
            if(freq[1]%2 == 0) {
                ans = freq[1]-1;
            } else {
                ans = freq[1];
            }
        }

        if(freq[0] >= 1) {
            if(freq[0]%2 == 0) {
                ans = max(ans, freq[0]-1);
            } else {
                ans = max(ans, freq[0]);
            }
        }
        
        for(int i=0;i<nums.size();i++) {
            long long seq = nums[i];
            int count = 0;

            if(seq == 0 || seq == 1) {
                continue;
            }

            while(freq[seq] >= 2) {
                count = count + 2;
                seq = seq*seq;
            }

            if(seq == nums[i]) {
                ans = max(ans, 1);
            } else if(freq[seq] == 1) {
                ans = max(ans, count+1);
            } else {
                ans = max(ans, count-1);
            }   
        }

        return ans;
        
    }
};