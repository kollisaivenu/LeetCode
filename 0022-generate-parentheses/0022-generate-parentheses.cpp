class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str = "";
        make(0, 0, n, ans, str);
        return ans;
    }

    void make(int left, int right, int n, vector<string>&ans, string str) {
        if(str.length() == 2*n) {
            ans.push_back(str);
            return;
        }

        if(left == right) {
            make(left+1, right, n, ans, str+'(');
        } else if(left<n){
            make(left+1, right, n, ans, str + '(');
            make(left, right+1, n, ans, str + ')');
        } else if(left == n) {
            make(left, right+1, n, ans, str + ')');
        }
    }
};