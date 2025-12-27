class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        backtrack(arr, 0, "", ans);
        return ans;
    }

    void backtrack(vector<string>& arr, int index, string str, int &ans) {
        if(index >= arr.size()) {
            if (str.length() > ans) {
                ans = str.length();
            }
            return;
        }
        vector<bool>isPresent(26, false);

        for(int i=0;i<str.length();i++) {
            isPresent[str[i]-'a'] = true;
        }

        bool cont = true;
        for(int i=0;i<arr[index].length();i++) {
            if(isPresent[arr[index][i]-'a']) {
                cont = false;
                break;
            }
            isPresent[arr[index][i]-'a'] = true;
        }

        if (cont) {
            backtrack(arr, index+1, str+arr[index], ans);
        }
        backtrack(arr, index+1, str, ans);
    }
};