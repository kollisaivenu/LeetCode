class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>noOfDevices(bank.size(), 0);

        for(int i=0;i<bank.size();i++) {
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j] == '1'){
                    noOfDevices[i]++;
                }
            }
        }

        int numOfLaserBeams = 0;

        for(int i=1;i<noOfDevices.size();i++){
            if(noOfDevices[i] > 0){
                for(int j=i-1;j>=0;j--){
                    if(noOfDevices[j] > 0) {
                        numOfLaserBeams += noOfDevices[i]*noOfDevices[j];
                        break;
                    }
                }
            }
        }

        return numOfLaserBeams;
        
    }
};