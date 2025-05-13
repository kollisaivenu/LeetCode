class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int>freqOfRemainder;
        freqOfRemainder[0]++;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int mod = euclideanMod(sum, k);
            count += freqOfRemainder[mod];
            freqOfRemainder[mod]++;
        }

        return count;
    }

    int euclideanMod(int a, int b){
        int r = a%b;

        if(r<0){
            return r+b;
        }
        return r;
    }
};