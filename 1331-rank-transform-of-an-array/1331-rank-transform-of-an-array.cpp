class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>nums;
        map<int, int>ranks;
        for(int i=0;i<arr.size();i++) {
            nums.insert(arr[i]);
        }
        int rank = 1;
        for(int num: nums) {
            ranks[num] = rank;
            rank++;
        }

        vector<int>ans;

        for(int num: arr) {
            ans.push_back(ranks[num]);
        }

        return ans;
    }
};