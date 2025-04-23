class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int>sumFreq;
        int count = 0, maxGroupSize = INT_MIN;

        for(int i=1;i<=n;i++){
            int sumOfDigits = sum(i);
            sumFreq[sumOfDigits]++;
            maxGroupSize = max(maxGroupSize, sumFreq[sumOfDigits]);

        }
        
        for (const auto& pair : sumFreq) {
            if(pair.second == maxGroupSize){
                count++;
            }
        }
        return count;
    }

    int sum(int num){
        int sumOfDigits = 0;
        while(num){
            sumOfDigits += num%10;
            num = num/10;
        }

        return sumOfDigits;
    }
};