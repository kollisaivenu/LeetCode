class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, bool>m;
        string ans = "";
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = true;
        }
        int l = nums[0].size();

        if(recursion(m, ans, l, "")){
            return ans;
        } else {
            return "";
        }
    }

    bool recursion(unordered_map<string, bool>m, string &ans, int l, string s){
        bool r = false;
        
        if(s.length() == l && m[s] == false){
            ans = s;
            return true;
        } else if(s.length() == l && m[s] == true){
            return false;
        } else {
            r = r || recursion(m, ans, l, s+"0");
            r = r || recursion(m, ans, l, s+"1");
        }

        
        return r;
    }
};