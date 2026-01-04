class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        vector<bool>sorted(strs.size()-1, false);

        for(int i=0;i<strs[0].length();i++){
            bool toDelete = false;
            for(int j=1;j<strs.size();j++){
                if(sorted[j-1] == false) {
                    if(strs[j-1][i] > strs[j][i]) {
                        toDelete = true;
                        ans++;
                        break;
                    }
                }
            }

            if(!toDelete) {
                for(int j=1;j<strs.size();j++) {
                    if(strs[j-1][i] < strs[j][i]) {
                        sorted[j-1] = true;
                    }
                }
            }
            
        }

        return ans;   
    }
};