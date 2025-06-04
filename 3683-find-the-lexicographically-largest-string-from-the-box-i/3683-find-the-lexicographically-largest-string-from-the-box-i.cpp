class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }

        priority_queue<pair<int, int>>pq;
        string ans = "";
        int maxChar = 0;
        for(int i=0;i<word.length();i++){
            maxChar = max(maxChar, word[i]-'a');
        }
        vector<int>indices;
        for(int i=0;i<word.length();i++){
            if((word[i]-'a') == maxChar){

                if(i >= numFriends-1){
                    string temp = getSubString(word, i, word.size()-1);

                    if(temp > ans){
                        ans = temp;
                    }
                } else {
                    int leftToGetCharacter = numFriends - i - 1;
                    string temp = getSubString(word, i, word.size()-1-leftToGetCharacter);
                
                    if(temp > ans){
                        ans = temp;
                    }
                }
                
            }
        }
        return ans;
    }

    string getSubString(string &s1, int start, int end){
        string ans = "";
        for(int i=start;i<=end;i++){
            ans += s1[i];
        }

        return ans;
    }
};