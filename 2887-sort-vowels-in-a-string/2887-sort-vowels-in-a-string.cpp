class Solution {
public:
    string sortVowels(string s) {
        vector<int>listOfVowels;

        for(int i=0; i<s.length(); i++){
            if(isVowel(s[i])){
                listOfVowels.push_back(s[i]);
            }
        }
        sort(listOfVowels.begin(), listOfVowels.end());
        for(int i=0,j=0; i<s.length(); i++){
            if(isVowel(s[i])){
                s[i] = listOfVowels[j];
                j++;
            }
        }
        return s;
    }
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
};