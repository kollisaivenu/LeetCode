class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string>eligibleBusinessLines;
        eligibleBusinessLines.push_back("electronics");
        eligibleBusinessLines.push_back("grocery");
        eligibleBusinessLines.push_back("pharmacy");
        eligibleBusinessLines.push_back("restaurant");
        vector<string>finalCodes;
        for(int i=0;i<4;i++){
            vector<string>codes;
            for(int j=0;j<businessLine.size();j++){
                if(businessLine[j] == eligibleBusinessLines[i] && isActive[j] && isValid(code[j])){
                    codes.push_back(code[j]);
                }
            }
            sort(codes.begin(), codes.end());
            finalCodes.insert(finalCodes.end(), codes.begin(), codes.end());
        }
        return finalCodes;
    }

    bool isValid(string code){
        if(code == ""){
            return false;
        }
        for(int i=0;i<code.length();i++){
            if(code[i] == '_' || (code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= '0' && code[i] <= '9')){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};