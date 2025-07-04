class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        for(int i=1;i<k;i=i*2){
            str = mod(str);
        }
        return str[k-1];
    }
    string mod(string str){
        string app = "";

        for(int i=0;i<str.length();i++){
            app+=(char)((str[i]-'a'+1)%26+'a');
        }

        return str+app;
    }
};