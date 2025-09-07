class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        ans.reserve(n);
        if(n%2 == 0){
            int mid = n/2;

            for(int i=1;i<=mid;i++){
                ans.push_back(i);
                ans.push_back(-i);
            }
        } else {
            int mid = (n-1)/2;

            ans.push_back(0);
            for(int i=1;i<=mid;i++){
                ans.push_back(i);
                ans.push_back(-i);
            }
        }

        return ans;
    }
};