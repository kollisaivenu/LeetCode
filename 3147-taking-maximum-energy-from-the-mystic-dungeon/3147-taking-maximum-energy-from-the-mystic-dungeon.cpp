class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>dp(energy.size(), 0);
        int maxEnergy = INT_MIN;
        for(int i=energy.size()-1;i>=0;i--){
            if(i+k >= energy.size()){
                dp[i] = energy[i];
            } else {
                dp[i] = energy[i] +dp[i+k];
            }

            maxEnergy = max(maxEnergy, dp[i]);
        }

        return maxEnergy;
    }
};