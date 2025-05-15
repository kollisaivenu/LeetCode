class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int currGroup;
        for(int i=0;i<groups.size();i++){
            if(i == 0 || groups[i] != currGroup){
                currGroup = groups[i];
                ans.push_back(words[i]);
            } 
        }

        return ans;
    }
};