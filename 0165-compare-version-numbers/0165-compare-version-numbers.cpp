class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>num1, num2;
        
        string str = "";
        for(int i=0;i<version1.size();i++){
            if(version1[i] == '.'){
                num1.push_back(stoi(str));
                str = "";
            } else if(i == version1.size()-1){
                str += version1[i];
                num1.push_back(stoi(str));
                str = "";
            } else {
                str += version1[i];
            }
        }

        for(int i=0;i<version2.size();i++){
            if(version2[i] == '.'){
                num2.push_back(stoi(str));
                str = "";
            } else if(i == version2.size()-1){
                str += version2[i];
                num2.push_back(stoi(str));
            } else {
                str += version2[i];
            }
        }

        if(num1.size() > num2.size()){
            while(num2.size() < num1.size()){
                num2.push_back(0);
            }
        } else {
            while(num1.size() < num2.size()){
                num1.push_back(0);
            }
        }

        for(int i=0;i<num1.size();i++){
            if(num1[i] > num2[i]){
                return 1;
            } else if(num2[i] > num1[i]){
                return -1;
            }
        }

        return 0;

    }
};