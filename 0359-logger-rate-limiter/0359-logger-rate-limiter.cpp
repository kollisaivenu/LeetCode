class Logger {
private:
    map<string, int>f;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(f.find(message) == f.end()) {
            f[message] = timestamp;
            return true;
        } else {
            if(f[message] + 10 <= timestamp) {
                f[message] = timestamp;
                return true;
            } else {
                return false;
            }
        }
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */