class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i=0;i<s.length();i++) {
            for(int j=i,k=i;j>=0 && k<s.length(); j--,k++) {
                if(s[j] == s[k]) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<s.length();i++) {
            for(int j=i-1,k=i;j>=0 && k<s.length(); j--,k++) {
                if(s[j] == s[k]) {
                    ans++;
                } else {
                    break;
                }
            }
        } 

        return ans;
    }
};