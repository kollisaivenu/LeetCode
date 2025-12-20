class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i=0;i<strs[0].length();i++) {
            bool sorted = true;
            for(int j=1;j<strs.size();j++) {
                if(strs[j][i] < strs[j-1][i]) {
                    sorted = false;
                    break;
                }
            }

            if(!sorted) {
                ans++;
            }
        }
        
        return ans;
    }
};