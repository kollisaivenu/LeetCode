class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int c = queries[i][2];
            int d = queries[i][3];

            for(int j=a;j<=b;j=j+c){
                nums[j] = (1LL*nums[j]*d)%1000000007;
            }
        }

        int x = 0;

        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
        }
        
        return x;
    }
};