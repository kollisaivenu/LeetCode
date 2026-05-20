class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, bool>a;
        vector<int>ans(A.size(), 0);
        int count = 0;
        for(int i=0;i<A.size();i++) {
            int count = 0;
            for(int j=0;j<=i;j++) {
                a[A[j]] = true;
            }

            for(int j=0;j<=i;j++) {
                if(a[B[j]]) {
                    count++;
                }
            }
            ans[i] = count;
        }

        return ans;
    }
};