class Solution {
public:
    string generateTag(string caption) {
        string validCaption = "#";
        bool reachedFirstChar = false;
        char capitalize = false;
        
        for(int i=0;i<caption.length();i++){
            if(caption[i] == ' ' && reachedFirstChar){
                capitalize = true;
            } else if(caption[i] != ' ' && capitalize){
                validCaption += toupper(caption[i]);
                capitalize = false;
            } else if(caption[i] != ' '){
                validCaption += tolower(caption[i]);
                reachedFirstChar = true;   
            }

            if(validCaption.length() == 100){
                break;
            }
        }

        return validCaption;
        
    }
};