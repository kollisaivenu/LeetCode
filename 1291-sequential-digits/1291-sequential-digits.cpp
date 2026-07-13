class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digitsLow = noOfDigits(low);
        int digitsHigh = noOfDigits(high);
        vector<int> ans;
        for(int i=digitsLow;i<=digitsHigh;i++) {
            for(int digit=1;digit<=9;digit++) {
                int num = 0;
                if(digit + i-1 > 9) {
                    continue;
                }
                for(int j=i-1, k=digit;j>=0 && k <= 9;j--, k++) {
                    num = num + pow(10, j)*k;
                }

                if(num >= low && num <= high) {
                    ans.push_back(num);
                }   
            }
        }

        return ans;
        
    }

    int noOfDigits(int num) {
        int ans = 0;

        while(num) {
            num = num/10;
            ans++;
        }

        return ans;
    }
};