class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<bool>upper(26, false);
        vector<bool>lower(26, false);
        for(int i=0;i<word.size();i++) {
            if(isupper(word[i])) {
                upper[word[i]-'A'] = true;
            } else {
                lower[word[i]-'a'] = true;
            }
        }

        for(int i=0;i<26;i++) {
            if(upper[i] && lower[i]) {
                count++;
            }
        }

        return count;
    }
};