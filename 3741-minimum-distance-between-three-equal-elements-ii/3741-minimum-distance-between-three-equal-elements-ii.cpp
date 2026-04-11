class Solution {
public:
    static bool cmp(pair<int, int>&p1, pair<int, int>&p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }

        return p1.first < p2.first;
    }

    int minimumDistance(vector<int>& nums) {
        vector<pair<int, int>>num_index;
        for(int i=0;i<nums.size();i++) {
            num_index.push_back(make_pair(nums[i], i));
        }

        sort(num_index.begin(), num_index.end(), cmp);
        
        int ans = INT_MAX;
        for(int i=0;i<num_index.size();i++) {
            if(i+2 < num_index.size() && num_index[i+2].first == num_index[i].first) {
                int lowest_index = num_index[i].second;
                int highest_index = num_index[i+2].second;
                ans = min(ans, 2*(highest_index - lowest_index));
            }
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};