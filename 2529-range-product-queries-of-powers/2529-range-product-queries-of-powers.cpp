class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powersOf2;
        int power = 0;
        while(n){
            if((n & 1) == 1){
                powersOf2.push_back(pow(2, power));
            }
            n = n >> 1;
            power++;
        }

        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            long long prod = 1;

            for(int j=queries[i][0]; j <= queries[i][1]; j++){
                prod = (prod*powersOf2[j])%1000000007;
            }
            ans.push_back(prod);
        }

        return ans;
    }
};