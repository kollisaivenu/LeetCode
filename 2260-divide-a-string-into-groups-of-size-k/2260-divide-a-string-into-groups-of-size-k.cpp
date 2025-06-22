class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int j=0;
        string word = "";
        
        for(int i=0;i<s.length();i++){
            if(j<k){
                word += s[i];
                j++;
            } else {
                ans.push_back(word);
                word = s[i];
                j = 1;
            }
        }
        
        while(word.length() < k){
            word += fill;
        }

        ans.push_back(word);

        return ans;
    }
};