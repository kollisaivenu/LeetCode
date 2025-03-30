class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>totalFreq(26, 0);
        vector<int>currentFreq(26, 0);
        vector<int>ans;

        for(int i=0;i<s.length();i++){
            totalFreq[s[i]-'a']++;
        }
        int lastIndex = 0;
        for(int i=0;i<s.length();i++){
            currentFreq[s[i]-'a']++;

            if(partitionFeasible(totalFreq, currentFreq)){
                int size = i - lastIndex + 1;
                lastIndex = i + 1;
                ans.push_back(size);
            }
        }

        return ans;
    }
    bool partitionFeasible(vector<int>&totalFreq, vector<int>&currentFreq){
        for(int i=0;i<26;i++){
            if(totalFreq[i] == currentFreq[i] || currentFreq[i] == 0){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};