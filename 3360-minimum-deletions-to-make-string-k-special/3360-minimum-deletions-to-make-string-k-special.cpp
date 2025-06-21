class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26, 0);

        for(int i=0;i<word.length();i++){
            freq[word[i]-'a']++;
        }

        int ans = INT_MAX;

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                int count = 0;
                for(int j=0;j<26;j++){
                    if(freq[j] > 0){
                        if(freq[j]<freq[i]){
                            count += freq[j];
                        } else if(freq[i] + k < freq[j]){
                            count += (freq[j] - freq[i] - k);
                        }
                    }
                }

                ans = min(ans, count);
            }
        }

        return ans;
    }
};