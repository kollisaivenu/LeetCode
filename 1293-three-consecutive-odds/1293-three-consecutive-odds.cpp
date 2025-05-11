class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int last = 2;

        for(;last<arr.size();last++){
            if((arr[last-2]%2 == 1) && (arr[last-1]%2 == 1) && (arr[last]%2 == 1)){
                return true;
            }
        }

        return false;
    }
};