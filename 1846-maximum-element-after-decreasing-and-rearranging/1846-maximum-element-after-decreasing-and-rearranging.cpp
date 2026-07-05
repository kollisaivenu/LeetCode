class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        int act_val = 1;

        for(int i=1;i<arr.size();i++) {
            if(arr[i] <= act_val) {
                ans = max(ans, arr[i]);
            } else {
                act_val++;
                ans = max(ans, act_val);
            }
        }

        return ans;
        
    }
};