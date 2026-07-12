class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int>ranks;
        for(int i=0;i<arr.size();i++) {
            ranks[arr[i]] = 1;
        }

        int rank = 1;
        for(auto &p: ranks) {
            p.second = rank;
            rank++;
        }

        vector<int>ans;

        for(int num: arr) {
            ans.push_back(ranks[num]);
        }

        return ans;
    }
};