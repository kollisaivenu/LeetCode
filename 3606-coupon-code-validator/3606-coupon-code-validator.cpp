class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> businessLineOrder = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<string>ans;
        for(string currentBusinessLine: businessLineOrder) {
            vector<string>codes;
            for(int i=0;i<businessLine.size();i++){
                if(businessLine[i] == currentBusinessLine && isActive[i] && isValidCode(code[i])) {
                    cout<<code[i]<<"\n";
                    codes.push_back(code[i]);
                }
            }

            sort(codes.begin(), codes.end());
            ans.insert(ans.end(), codes.begin(), codes.end());
        }

        return ans;
        
    }

    bool isValidCode(string code) {
        if (code.length() == 0) {
            return false;
        }
        
        for(int i=0;i<code.length();i++) {
            if(code[i] != '_'  && !isupper(code[i]) && !islower(code[i]) && !isdigit(code[i])) {
                return false;
            }
        }

        return true;
    }
};