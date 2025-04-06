class CombinationIterator {
public:
    vector<string>combinations;
    int index = 0;
    CombinationIterator(string characters, int combinationLength) {
        getCombinations("", 0, characters, combinationLength);
    }

    void getCombinations(string curr, int currIndex, string characters, int combinationLength){
        if(curr.length() == combinationLength){
            combinations.push_back(curr);
        }

        if(currIndex == characters.length()){
            return;
        }

        for(int i=currIndex;i<characters.size();i++){
            if(curr.length() < combinationLength){
                getCombinations(curr+characters[i], i+1, characters, combinationLength);
            }
        }
    }
    
    string next() {
        return combinations[index++];
    }
    
    bool hasNext() {
        if(index < combinations.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */