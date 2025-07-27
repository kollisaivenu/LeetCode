class Solution {
public:
    long long numOfSubsequences(string s) {
        vector<int>ls(s.length(), 0);
        vector<int>ts(s.length(), 0);

        for(int i=0;i<s.length();i++){
            if(s[i] == 'L' && i == 0){
                ls[i] = 1;
            } else if(s[i] == 'L' && i>0){
                ls[i] = ls[i-1] + 1;
            } else if(s[i] != 'L' && i == 0){
                ls[i] = 0;
            } else if(s[i] != 'L' && i > 0){
                ls[i] = ls[i-1];
            }
        }

        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == 'T' && i == s.length()-1){
                ts[i] = 1;
            } else if(s[i] == 'T' && i < s.length()-1){
                ts[i] = ts[i+1] + 1;
            } else if(s[i] != 'T' && i == s.length()-1){
                ts[i] = 0;
            } else if(s[i] != 'T' && i < s.length()-1){
                ts[i] = ts[i+1];
            }
        }

        long long ans = 0;
        long long curr_ans = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == 'C'){
                curr_ans += (ls[i]+1)*ts[i];
            }
        }

        
        
        ans = max(ans, curr_ans);
        curr_ans = 0;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == 'C'){
               curr_ans += (ls[i])*(ts[i]+1); 
            }
        }
        ans = max(ans, curr_ans);
        
        long long total_sub = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'C'){
                total_sub += ls[i]*ts[i];
            }
        }
        //cout<<ans<<"\n";
        for(int i=0;i<s.length();i++){
            ans = max(ans, total_sub+((long long)ls[i]*ts[i]));
        }
        
        return ans;
        
    }
};