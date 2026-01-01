class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryover = 0,sum = 0,flag = 0;
        vector<int> v;
        for(int i = digits.size()-1;i>=0;i--){
            if(flag == 0){
                sum = digits[i]  + 1;
                flag = 1;
            } else {
                sum = digits[i]  + carryover;
            }
            int d = sum%10;
            carryover = sum/10;
            v.push_back(d);
        }
        if(carryover > 0){
            v.push_back(carryover);
        }
        reverse(v.begin(), v.end());
        return v;
        
    }
};