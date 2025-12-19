class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<int>vis(n, 0);
        permute(ans, vis, 0);
        return ans;
    }

    void permute(int &ans, vector<int>&vis, int index) {
        if(index == vis.size()) {
            ans++;
        }

        for(int i=0;i<vis.size();i++){
            if(vis[i] == 0) {
                if(((i+1)%(index+1)) == 0 || ((index+1)%(i+1)) == 0) {
                    vis[i] = 1;
                    permute(ans, vis, index+1);
                    vis[i] = 0;
                }
            }
        }
    }
};