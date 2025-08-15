class Solution {
public:
    string largestGoodInteger(string num) {
        int i=0,j=1,k=2;
        int m = 0;
        string ans = "";
        for(;k<num.size();i++,j++,k++){
            if(num[i] == num[j] && num[j] == num[k]){
                if(num[i] - '0' >= m){
                    ans = "";
                    m = num[i] - '0';
                    ans = ans + num[i] + num[j] + num[k];
                }
            }
        }

        return ans;
        
    }
};