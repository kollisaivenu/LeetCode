class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        for(int i=0;i<words.size();i++) {
            if(words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, (int)words.size() - dist));
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};