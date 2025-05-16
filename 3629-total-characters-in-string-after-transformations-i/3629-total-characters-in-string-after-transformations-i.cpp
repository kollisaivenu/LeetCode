class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>freq(26, 0);
        int MOD = 1000000007;
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        for(int i=1;i<=t;i++){
            vector<int>temp(26, 0);
            for(int i=0;i<25;i++){
                if(freq[i] > 0){
                    temp[i+1] = freq[i];
                }
            }

            if(freq[25] > 0){
                temp[0] = (temp[0] + freq[25])%MOD;
                temp[1] = (temp[1] + freq[25])%MOD;
            }

            freq = temp;

        }

        int len = 0;

        for(int i=0;i<26;i++){
            len = (len + freq[i])%MOD;
        }
        return len;
    }
};