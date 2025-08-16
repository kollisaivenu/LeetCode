class Solution {
public:
    int maximum69Number (int num) {
        vector<int>n;
        while(num){
            int digit = num%10;
            num = num/10;
            n.push_back(digit);
        }
        reverse(n.begin(), n.end());
        
        int ans = 0;
        bool changed = false;
        for(int i=0;i<n.size();i++){
            if(n[i] == 6 && !changed){
                
                ans = ans*10+9;
                changed = true;
            } else {
                ans = ans*10+n[i];
            }
        }
        return ans;
    }
};