class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>m;
        int mid = 0, count=0;
        string middle = "";
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }

        for(int i=0;i<words.size();i++){
            if(words[i][0] == words[i][1] && m[words[i]]%2 == 1 && m[words[i]] > mid){
                mid = m[words[i]];
                middle = words[i];
            }
        }
        cout<<mid<<"\n";
        cout<<middle<<"\n";
        for(int i=0;i<words.size();i++){

            if(words[i][0] == words[i][1]){
                
                if(words[i] != middle){
                    if(m[words[i]]%2 == 0){
                        count += m[words[i]]*2;
                    } else {
                        count += (m[words[i]]-1)*2;
                    }
                    m.erase(words[i]);
                }
            } else {
                string s = ""s + words[i][1] + words[i][0];

                if(m.find(s) != m.end()){
                    count = count + min(m[words[i]], m[s])*4;
                    m.erase(s);
                    m.erase(words[i]);
                }
            }
            
        }

        return count + 2*mid;

        
    }
};