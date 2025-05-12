class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>freq(10, 0);
        vector<int>ans;
        for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
        }

        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=8;k=k+2){
                    vector<int>numFreq(10, 0);
                    numFreq[i]++;
                    numFreq[j]++;
                    numFreq[k]++;

                    if(numFreq[i] <= freq[i] && numFreq[j] <= freq[j] && numFreq[k] <= freq[k]){
                        ans.push_back(i*100+j*10+k);
                    }
                }
            }
        }

        return ans;


    }
};