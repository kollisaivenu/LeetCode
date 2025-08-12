class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int powerOf2 = 1;

        vector<vector<int>>powersOf2;

        while(powerOf2 > 0){
            powersOf2.push_back(getCountOfDigits(powerOf2));
            powerOf2 = powerOf2 << 1;
        }

        int len = powersOf2.size();
        vector<int>freq = getCountOfDigits(n);

        for(int i=0;i<len;i++){
            if(compareFreq(freq, powersOf2[i])){
                return true;
            }
        }

        return false;

    }

    vector<int> getCountOfDigits(int no){
        vector<int>freq(10, 0);
        
        while(no){
            int digit = no%10;
            no = no/10;
            freq[digit]++;
        }
        return freq;
    }

    bool compareFreq(vector<int>&freq1, vector<int>&freq2){
        if(freq1.size() < 10  || freq2.size() < 10){
            return false;
        }

        for(int i=0;i<10;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;
    }
};