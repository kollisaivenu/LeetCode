class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        priority_queue<int>pq;

        for(int i=0;i<nums.size();i++){
            pq.push((nums[i]^k) - nums[i]);
            sum += nums[i];
        }

        while(pq.size()>1){
            int delta1 = pq.top();
            pq.pop();
            int delta2 = pq.top();
            pq.pop();

            if(delta1 + delta2 > 0){
                sum += (delta1 + delta2);
            } else {
                break;
            }
        }

        return sum;
        
    }
};