class Solution {
public:
    string countAndSay(int n) {
        vector<string>ans(n);
        ans[0] = "1";

        for(int i=1;i<n;i++){
            ans[i] = rle(ans[i-1]);
        }
        return ans[n-1];
    }

    string rle(string s){
        int count = 1;
        char ch = s[0];
        string ans = "";
        for(int i=1;i<s.length();i++){
            if(s[i] == ch){
                count++;
            } else {
                ans = ans + to_string(count)+ch;
                ch = s[i];
                count = 1;
            }
        }
        ans = ans + to_string(count)+ch;
        return ans;
    }
};