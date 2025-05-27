class Solution {
public:
    string multiply(string num1, string num2) {
        //cout<<multiplyWithSingleNumber("2", '3');
        string larger = "", smaller = "";
        if(num1.length()>num2.length()){
            larger = num1;
            smaller = num2;
        } else {
            larger = num2;
            smaller = num1;
        }

        string suffix = "";
        string ans = "0";

        for(int i=smaller.length()-1;i>=0;i--){
            string inter1 = multiplyWithSingleNumber(larger, smaller[i]) + suffix;
            ans = add(inter1, ans);
            suffix += "0";
        }

        return ans;
    
    }

    string multiplyWithSingleNumber(string no1, char digit){
        string ans = "";
        int no = digit-'0', carry = 0;

        if(no == 0){
            return "0";
        }
    
        for(int i=no1.length()-1;i>=0;i--){
            int digit = no1[i]-'0';
            int num = digit*no + carry;

            if(num<=9){
                carry = 0;
                ans += to_string(num);
            } else {
                carry = num/10;
                ans += to_string(num%10);
            }

        }

        if(carry > 0){
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string add(string no1, string no2){
        string larger = "", smaller = "", ans="";
        if(no1.length()>no2.length()){
            larger = no1;
            smaller = no2;
        } else {
            larger = no2;
            smaller = no1;
        }
        int gap = larger.length()-smaller.length();
        string prefix = "";

        for(int i=0;i<gap;i++){
            prefix += '0';
        }
        smaller = prefix + smaller;

        int carry = 0;
        for(int i=larger.length()-1;i>=0;i--){
            int digit1 = larger[i]-'0';
            int digit2 = smaller[i]-'0';

            int no = carry + digit1 + digit2;

            if(no<=9){
                carry = 0;
                ans += to_string(no);
            } else {
                carry = no/10;
                ans += to_string(no%10);
            }
        }

        if(carry > 0){
            ans += to_string(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};