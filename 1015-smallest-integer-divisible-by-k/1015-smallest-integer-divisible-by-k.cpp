class Solution {
public:
    int smallestRepunitDivByK(int k) {
        map<int, bool>m;
        int no = 0, len = 0;

        while(!m[no]) {
            m[no] = true;
            no = ((10*no)%k + 1)%k;
            len++;

            if(no == 0){
                return len;
            }
        }

        return -1;
    }
};