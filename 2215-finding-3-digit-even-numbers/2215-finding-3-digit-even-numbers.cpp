class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int, bool>isVis;
        vector<int>ans;
        sort(digits.begin(), digits.end());

        for(int i=0;i<digits.size();i++){
            if(digits[i] != 0){
                for(int j=0;j<digits.size();j++){
                    if(j == i) continue;
                    
                    for(int k=0;k<digits.size();k++){
                        if(k == i || k == j) continue;
                        
                        if(digits[k]%2 == 0){
                            int num = digits[i]*100 + digits[j]*10 + digits[k];

                            if(!isVis[num]){
                                ans.push_back(num);
                                isVis[num] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};