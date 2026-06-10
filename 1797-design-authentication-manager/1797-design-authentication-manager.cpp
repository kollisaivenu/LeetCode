class AuthenticationManager {
public:
    unordered_map<string, int>tokenMap;
    int timeToLive;
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
        
    }
    
    void generate(string tokenId, int currentTime) {
        this->tokenMap[tokenId] = currentTime + this->timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokenMap.contains(tokenId)) {
            if(tokenMap[tokenId] > currentTime) {
                tokenMap[tokenId] = currentTime + this->timeToLive;
            }
        } 
        
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for(auto pair: tokenMap) {
            if(pair.second > currentTime) {
                ans++;
            }
        }
        return ans;
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */