class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() > b.length()){
            string str = getZeros(a.length() - b.length());
            b = str + b;
        } else {
            string str = getZeros(b.length() - a.length());
            a = str + a;
        }
        string ans = "";
        char carryover = '0';
        for(int i=a.length()-1;i>=0;i--){
            if(a[i] == '0' && b[i] == '0' && carryover == '0'){
                ans = '0' + ans;
                carryover = '0';
            }else if(a[i] == '0' && b[i] == '0' && carryover == '1'){
                ans = '1' + ans;
                carryover = '0';
            } else if (a[i] == '1' && b[i] == '1' && carryover == '0'){
                ans = '0' + ans;
                carryover = '1';
            } else if(a[i] == '1' && b[i] == '1' && carryover == '1'){
                ans = '1' + ans;
                carryover = '1';
            } else if(carryover == '1'){
                ans =  '0' + ans;
                carryover = '1';
            } else {
                ans = '1' + ans;
                carryover = '0';
            }
        }
        if(carryover == '1'){
            ans = '1' + ans;
        }
        return ans;
    }

    string getZeros(int noOfZeros){
        string str = "";
        while(noOfZeros){
            str = str + "0";
            noOfZeros--;
        }

        return str;
    }
};