class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>freq;
        int mini = INT_MAX;
        for(int i=0;i<nums1.size();i++) {
            freq[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++) {
            if(freq[nums2[i]] > 0) {
                mini = min(nums2[i], mini);
            }
        }
        
        if(mini == INT_MAX) {
            return -1;
        } else {
            return mini;
        }
        
    }
};