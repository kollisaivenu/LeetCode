class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<=4;i++) {
            if(turnedOn - i <= 6) {
                for(int j=0;j<=11;j++) {
                    if(numOfBits(j) == i) {
                        string hr = to_string(j);

                        for(int k=0;k<=59;k++) {
                            if(numOfBits(k) == (turnedOn-i)) {
                                string min;
                                if(k>=0 && k<= 9) {
                                    min = "0" + to_string(k);
                                } else {
                                    min = to_string(k);
                                }
                                ans.push_back(hr+":"+min);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }

    int numOfBits(int no) {
        int count = 0;
        while(no) {
            if(no & 1) {
                count++;
            }

            no = no>>1;
        }

        return count;
    } 
};