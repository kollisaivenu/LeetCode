class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int ops = 0;
        vector<int>a(nums);
        vector<int>b(nums);
        
        for(int i=0;i<a.size()-1;i++){
            if(a[i] == -1){
                a[i] = a[i]*-1;
                a[i+1] = a[i+1]*-1;
                ops++;
            }
        }
        if(ops <= k){
            bool flag = true;
            for(int i=0;i<a.size();i++){
                if(a[i] == -1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        ops = 0;
        for(int i=0;i<b.size()-1;i++){
            if(b[i] == 1){
                b[i] = b[i]*-1;
                b[i+1] = b[i+1]*-1;
                ops++;
            }
        }

        if(ops <= k){
            bool flag = true;
            for(int i=0;i<b.size();i++){
                if(b[i] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }

        return false;
    }
};