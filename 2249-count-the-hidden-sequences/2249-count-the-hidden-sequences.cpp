class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int count = 0;
        vector<long long>prefixSum(differences.size(), 0);
        prefixSum[0] = differences[0];
        long long minDifference = differences[0], maxDifference = differences[0];
        
        for(int i=1;i<differences.size();i++){
            prefixSum[i] = differences[i] + prefixSum[i-1];
            minDifference = min(minDifference, prefixSum[i]);
            maxDifference = max(maxDifference, prefixSum[i]);
        }

        for(int start=lower;start<=upper;start++){
            if((minDifference+start >= lower && minDifference+start <= upper) && maxDifference+start >= lower && maxDifference+start <= upper){
                count++;
            }
        }

        return count;        
    }
};