class Solution {
public:
    int possibleStringCount(string word) {
        vector<int>freq;

        char ch = '1';

        for(int i=0;i<word.length();i++){
            if(ch != word[i]){
                ch = word[i];
                freq.push_back(1);
            } else {
                int lastIndex = freq.size()-1;
                freq[lastIndex]++;
            }
        }
        
        int ans = 0;
        for(int i=0;i<freq.size();i++){
            if(i != freq.size()-1){
                ans += (freq[i]-1);
            } else {
                ans += freq[i];
            }
        }

        return ans;
        
    }
};