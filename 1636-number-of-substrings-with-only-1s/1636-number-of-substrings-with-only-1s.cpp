class Solution {
public:
    int numSub(string s) {
        map<int, long long>m;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){
                int j=0;
                while(i<s.length() && s[i] == '1'){
                    j++;
                    i++;
                }

                m[j]++;
            }
        }
        long long ans = 0;
        for(auto itr = m.begin();itr!=m.end();itr++){
            
            long long len = itr->first;
            ans += (len*(len+1)/2)*itr->second;
        }

        return ans%1000000007;
    }
};