class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>freq;
        string palin = "";
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        
        for(int i=0;i<26;i++){
            if(freq[char(i+97)]%2 == 1){
                palin = char(i+97);
                freq[i] -= 1;
            }
        }
        string firstHalf = "";
        for(int i=0;i<26;i++){
            if(freq[char(i+97)] > 0){
                for(int j=0;j<freq[char(i+97)]/2;j++){
                    firstHalf += char(i+97);
                }
            }
        }
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        return firstHalf + palin + secondHalf;
    }
};