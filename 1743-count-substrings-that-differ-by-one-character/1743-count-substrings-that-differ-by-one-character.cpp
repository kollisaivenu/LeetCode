class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                int curr_ans = 0;
                if(s[i] != t[j]){
                    int left_subarrays = 0;
                    int go_left_i = i-1;
                    int go_left_j = j-1;

                    while(go_left_i >=0 && go_left_j >= 0 && s[go_left_i] == t[go_left_j]){
                        left_subarrays++;
                        go_left_i--;
                        go_left_j--;
                    }

                    int right_subarrays = 0;
                    int go_right_i = i+1;
                    int go_right_j = j+1;

                    while(go_right_i < s.length() && go_right_j < t.length() && s[go_right_i] == t[go_right_j]){
                        right_subarrays++;
                        go_right_i++;
                        go_right_j++;
                    }
                    curr_ans += (1 + left_subarrays)*(1 + right_subarrays);
                }
                ans += curr_ans;

            }
        }
        return ans;   
    }
};