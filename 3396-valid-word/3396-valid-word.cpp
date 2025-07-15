class Solution {
public:
    bool isValid(string word) {
        bool containsVowel = false;
        bool containsConsonant = false;

        if (word.length() < 3){
            return false;
        }

        for(int i=0;i<word.size();i++){
            if(isInvalid(word[i])){
                return false;
            }

            if(isVowel(word[i])){
                containsVowel = true;
            }

            if(isConsonant(word[i])){
                containsConsonant = true;
            }
        }

        return containsVowel && containsConsonant;
    }

    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    bool isConsonant(char ch){
        if((isupper(ch) || islower(ch)) && !isVowel(ch)){
            return true;
        }
        return false;
    }

    bool isInvalid(char ch){
        return !isupper(ch) && !islower(ch) && !isdigit(ch);
    }

};