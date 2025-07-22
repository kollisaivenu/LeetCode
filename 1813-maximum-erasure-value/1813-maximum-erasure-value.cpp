class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int>index;
        int i=0, j=0, ans=INT_MIN, sum=0;

        for(int i=0;i<nums.size();i++){
            index[nums[i]] = -1;
        }

        while(j<nums.size()){

            if(index[nums[j]] == -1){
                sum += nums[j];
                index[nums[j]] = j;
            } else {
                ans = max(ans, sum);
                sum += nums[j];
    
                while(i<=index[nums[j]]){
                    sum -= nums[i];
                    index[nums[i]] = -1;
                    i++;
                }
                index[nums[j]] = j;
            }
            j++;
        }
        
        ans = max(ans, sum);
        return ans;   
    }
};