class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(!containsZero(i) && !containsZero(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }

        return ans;        
    }

    bool containsZero(int no) {
        while(no) {
            int digit = no%10;

            if(digit == 0){
                return true;
            }

            no = no/10;
        }

        return false;
    }
};