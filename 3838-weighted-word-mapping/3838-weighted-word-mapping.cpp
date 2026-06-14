class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string word: words) {
            int sum = 0;
            for(int i=0;i<word.length();i++) {
                sum += weights[word[i]-'a'];
            }

            ans += (char)('z'-sum%26);
        }

        return ans;
    }
};