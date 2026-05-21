class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>prefixes;

        for(int i=0;i<arr1.size();i++) {
            int n = arr1[i];

            while(n > 0) {
                prefixes.insert(n);
                n = n/10;
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++) {
            int n = arr2[i];

            int len = to_string(arr2[i]).length();
            
            while(n > 0) {
                if (prefixes.contains(n)) {
                    ans = max(ans, len);
                }
                n = n/10;
                len--;
            }
        }

        return ans;
        
    }
};