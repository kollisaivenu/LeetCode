class FindSumPairs {
public:
    map<int, int>freq;
    vector<int>a;
    vector<int>b;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums2.size();i++){
            freq[nums2[i]]++;
        }
        a = nums1;
        b = nums2;
    }
    
    void add(int index, int val) {
        freq[b[index]]--;
        freq[b[index]+val]++;
        b[index] = b[index]+val;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<a.size();i++){
            ans += freq[tot-a[i]];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */