class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>index_upper(26, -1);
        vector<int>index_lower(26, -1);

        for(int i=0;i<word.length();i++) {
            if(isupper(word[i]) && index_upper[word[i]-'A'] == -1) {
                index_upper[word[i]-'A'] = i;
            }

            if(islower(word[i])) {
                index_lower[word[i]-'a'] = i;
            }
        }
        int count = 0;
        for(int i=0;i<26;i++) {
            if(index_upper[i] != -1 && index_lower[i] != -1 && index_upper[i] > index_lower[i]) {
                cout<<i<<"\n";
                count++;
            }
        }

        return count;
    }
};