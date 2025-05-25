class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>freq;
        int midTextLength = 0, length=0;
        string midText = "";

        for(int i=0;i<words.size();i++){
            freq[words[i]]++;
        }

        for(int i=0;i<words.size();i++){
            if(words[i][0] == words[i][1] && freq[words[i]]%2 == 1 && freq[words[i]] > midTextLength){
                midTextLength = 2*freq[words[i]];
                midText = words[i];
            }
        }
        for(int i=0;i<words.size();i++){

            if(words[i][0] == words[i][1]){
                
                if(words[i] != midText){
                    if(freq[words[i]]%2 == 0){
                        length += freq[words[i]]*2;
                    } else {
                        length += (freq[words[i]]-1)*2;
                    }
                    freq.erase(words[i]);
                }
            } else {
                string rev = ""s + words[i][1] + words[i][0];

                if(freq.find(rev) != freq.end()){
                    length = length + min(freq[words[i]], freq[rev])*4;
                    freq.erase(rev);
                    freq.erase(words[i]);
                }
            }
            
        }

        return length + midTextLength;

        
    }
};