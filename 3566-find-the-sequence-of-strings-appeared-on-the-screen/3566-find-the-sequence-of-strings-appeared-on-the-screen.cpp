class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string init = "";

        for(int i=0;i<target.length();i++){
            char lastChar = 'a';
            init += 'a';
            for(int j=0;j<26;j++){
                init[init.length()-1] = (char)(lastChar+j);
                ans.push_back(init);

                if((char)(lastChar+j) == target[i]){    
                    break;
                }
            }
        }

        return ans;   
    }
};