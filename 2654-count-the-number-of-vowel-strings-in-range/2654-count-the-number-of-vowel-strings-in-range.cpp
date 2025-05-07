class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i=left;i<=right;i++){
            if(isVowelString(words[i])){
                count++;
            }
        }

        return count;
    }

    bool isVowelString(string word){
        return isVowel(word[0]) && isVowel(word[word.length()-1]);
    }

    bool isVowel(char ch){
        return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
    }
};