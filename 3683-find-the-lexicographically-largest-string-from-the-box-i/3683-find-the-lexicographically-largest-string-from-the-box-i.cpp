class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }
        priority_queue<pair<int, int>>pq;
        string ans = "";
        for(int i=0;i<word.size();i++){
            pq.push(make_pair(word[i]-'a', i));
        }

        while(!pq.empty()){
            pair<int, int>p = pq.top();
            pq.pop();

            int numOfCharactersInBeginnning = p.second;

            if(numOfCharactersInBeginnning >= numFriends-1){
                string temp = getSubString(word, p.second, word.size()-1);

                if(temp > ans){
                    ans = temp;
                }
            } else {
                int leftToGetCharacter = numFriends - numOfCharactersInBeginnning - 1;
                string temp = getSubString(word, p.second, word.size()-1-leftToGetCharacter);
                
                if(temp > ans){
                    ans = temp;
                }
            }
        }

        return ans;
    }

    string getSubString(string s1, int start, int end){
        string ans = "";
        for(int i=start;i<=end;i++){
            ans += s1[i];
        }

        return ans;
    }
};