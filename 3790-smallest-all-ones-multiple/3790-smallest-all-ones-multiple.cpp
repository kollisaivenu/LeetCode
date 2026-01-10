class Solution {
public:
    int minAllOneMultiple(int k) {
        int rem = 1, len = 1;
        unordered_map<int, bool>alreadyVisited;

        while(rem != 0) {
            if(alreadyVisited[rem]) {
                return -1;
            }
            alreadyVisited[rem] = true;
            rem = (rem*10+1)%k;
            len++;
        }

        return len;   
    }
};