class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]] = -1;
        }
        int i=0, j=0, ans=INT_MIN, sum=0;
        while(j<nums.size()){
            if(m[nums[j]] == -1){
                sum += nums[j];
                m[nums[j]] = j;
            } else {
                ans = max(ans, sum);
                sum += nums[j];
    
                while(i<=m[nums[j]]){
                    sum -= nums[i];
                    m[nums[i]] = -1;
                    i++;
                }
                m[nums[j]] = j;
            }
            j++;
        }
        ans = max(ans, sum);
        return ans;   
    }
};