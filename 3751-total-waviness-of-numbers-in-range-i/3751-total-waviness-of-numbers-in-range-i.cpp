class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++) {
            ans += countWaviness(i);
        }

        return ans;
        
    }

    int countWaviness(int num) {
        vector<int>digits;

        while(num) {
            digits.push_back(num%10);
            num = num/10;
        }
        int waviness = 0;

        for(int i=1;i<digits.size()-1;i++) {
            if(digits[i] > digits[i+1] && digits[i] > digits[i-1]) {
                waviness++;
            } else if(digits[i] < digits[i+1] && digits[i] < digits[i-1]) {
                waviness++;
            }
        }

        return waviness; 
    }
};