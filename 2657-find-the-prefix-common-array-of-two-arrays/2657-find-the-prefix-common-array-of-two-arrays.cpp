class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>a;
        vector<int>ans(A.size(), 0);
        int count = 0;
        for(int i=0;i<A.size();i++) {
            a[A[i]]++;
            a[B[i]]++;

            if(A[i] == B[i]) {
                count++;
            } else {
                if(a[A[i]] == 2) {
                    count++;
                }

                if(a[B[i]] == 2) {
                    count++;
                }
            }
            
            ans[i] = count;
        }

        return ans;
    }
};