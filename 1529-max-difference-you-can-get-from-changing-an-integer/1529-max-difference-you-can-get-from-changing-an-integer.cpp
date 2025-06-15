class Solution {
public:
    int maxDiff(int num) {
        bool mapped = false;
        char orig, changed;

        string largestNumInStr = to_string(num);

        for(int i=0;i<largestNumInStr.length();i++){
            if(mapped == false && largestNumInStr[i] != '9'){
                orig = largestNumInStr[i];
                largestNumInStr[i] = '9';
                mapped = true;
            } else if(mapped && largestNumInStr[i] == orig){
                largestNumInStr[i] = '9';
            }
        }

        int largestNum = stoi(largestNumInStr);

        mapped = false;
        string smallestNumInStr = to_string(num);

        for(int i=0;i<smallestNumInStr.length();i++){
            if(mapped == false && smallestNumInStr[i] != '1' && i == 0){
                orig = smallestNumInStr[i];
                smallestNumInStr[i] = '1';
                changed = '1';
                mapped = true;
            } else if(mapped == false && smallestNumInStr[i] != '0' && i != 0 && smallestNumInStr[i] != '1'){
                orig = smallestNumInStr[i];
                smallestNumInStr[i] = '0';
                changed = '0';
                mapped = true;
            } else if(mapped && smallestNumInStr[i] == orig){
                smallestNumInStr[i] = changed;
            }
        }
        
        int smallestNum = stoi(smallestNumInStr);

        //cout<<smallestNum<<"\n";
        //cout<<largestNum<<"\n";

        return largestNum - smallestNum;
        
    }
};