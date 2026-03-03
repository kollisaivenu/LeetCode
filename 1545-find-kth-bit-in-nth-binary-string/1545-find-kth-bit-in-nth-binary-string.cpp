class Solution {
public:
    char findKthBit(int n, int k) {
        string str="0";
        for(int i=1;i<n;i++){
            str = con(str);
        }
        return str[k-1];
        
    }

    string con(string s){
        string inv = "";
        for(int i=0;i<s.length();i++){
            if(s[i] =='1'){
                inv+='0';
            } else {
                inv+= '1';
            }
        }
        reverse(inv.begin(), inv.end());
        return s+'1'+inv;
    }
};