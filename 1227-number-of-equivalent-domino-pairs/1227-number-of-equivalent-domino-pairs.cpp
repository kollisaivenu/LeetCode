class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int>freq;
        int ans = 0;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0]<=dominoes[i][1]){
                int no = dominoes[i][0]*10+dominoes[i][1];
                ans = ans + freq[no];
                freq[no]++;
            } else {
                int no = dominoes[i][1]*10+dominoes[i][0];
                ans = ans + freq[no];
                freq[no]++;
            }
        }

        return ans;
        
    }
};