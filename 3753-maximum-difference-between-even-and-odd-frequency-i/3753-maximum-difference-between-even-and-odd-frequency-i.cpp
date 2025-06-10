class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26, 0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        int max_odd_freq = INT_MIN, min_even_freq = INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]%2 == 0 && freq[i] != 0){
                min_even_freq = min(min_even_freq, freq[i]);
            } else if(freq[i]%2 == 1){
                max_odd_freq = max(max_odd_freq, freq[i]);
            }
        }

        return max_odd_freq - min_even_freq;
    }
};