class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeroes = 0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                zeroes++;
            }
        }
        int place = 0, ones = 0;
        long long no = 0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '1'){
                if(place <= 32){
                    no += pow(2, place);
                } else {
                    break;
                }
                
                if(no<=k){
                    ones++;
                } else {
                    break;
                }
            }
            place++;
        }

        return zeroes + ones;
    }
};