class Solution {
public:
    int longestContinuousSubstring(string s) {
        int global_ans = INT_MIN;
        int curr_ans = 1;

        for(int i=1;i<=s.length();i++) {
            if(((s[i]-'a') - (s[i-1]-'a')) == 1) {
                curr_ans++;
            } else {
                curr_ans = 1;
            }

            global_ans = max(curr_ans, global_ans);
        }

        return global_ans;
        
    }
};