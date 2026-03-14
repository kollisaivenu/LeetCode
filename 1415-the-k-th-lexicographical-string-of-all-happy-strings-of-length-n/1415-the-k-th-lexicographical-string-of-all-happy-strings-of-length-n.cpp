class Solution {
public:
    string getHappyString(int n, int k) {
        string ans = "";
        int curr = 0;
        backtrack("", n, k, ans, curr);
        return ans;
        
    }

    void backtrack(string curr, int n, int k, string &ans, int &curr_index){
        if(curr.length() == n){
            curr_index++;
            if(curr_index == k){
                ans = curr;
            }
            return;
        }
        if(curr.length() == 0){
            backtrack(curr+"a", n,k, ans, curr_index);
            backtrack(curr+"b", n,k, ans, curr_index);
            backtrack(curr+"c", n,k, ans, curr_index);
        } else if(curr[curr.length()-1] == 'a'){
            backtrack(curr+"b", n,k, ans, curr_index);
            backtrack(curr+"c", n,k, ans, curr_index);
        } else if(curr[curr.length()-1] == 'b'){
            backtrack(curr+"a", n,k, ans, curr_index);
            backtrack(curr+"c", n,k, ans, curr_index);
        } else {
            backtrack(curr+"a", n,k, ans, curr_index);
            backtrack(curr+"b", n,k, ans, curr_index);
        }

    }
};