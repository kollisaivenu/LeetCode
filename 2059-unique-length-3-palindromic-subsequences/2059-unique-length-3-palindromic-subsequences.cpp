class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26, 0);
        vector<int>right(26, 0);
        map<string, bool>vis;
        for(int i=1;i<s.length();i++){
            right[s[i]-'a']++;
        }
        int ans = 0;

        for(int i=1;i<s.length()-1;i++){
            right[s[i]-'a']--;
            left[s[i-1]-'a']++;

            for(int j=0;j<26;j++){
                if(left[j] >= 1 && right[j] >= 1){
                    string pos = "";
                    pos += (char)(j+'a');
                    pos += s[i];
                    pos += (char)(j+'a');
                    if(vis[pos] == false){
                        ans++;
                        vis[pos] = true;
                    }
                }
            }
            
            
        }
        return ans;
        
    }
};