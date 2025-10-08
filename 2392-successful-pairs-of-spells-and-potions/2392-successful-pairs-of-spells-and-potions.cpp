class Solution {
public:
    int func(long long int spell, vector<int> &potions, long long k){
        int noOfPotions = potions.size();
        int low = 0, high = potions.size()-1;
        long long int noOfPotionsThatGiveSuccess = 0;
        while(low<=high){
            long long int mid = (low+high)/2;
            long long int successNumber = potions[mid]*spell;
            if(successNumber>=k){
                if((noOfPotions-mid)>noOfPotionsThatGiveSuccess){
                    noOfPotionsThatGiveSuccess = noOfPotions-mid;
                }
                high=mid-1;
            } else {
                low = mid+1;
            }
        }
        return noOfPotionsThatGiveSuccess;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
            ans.push_back(func(spells[i], potions, success));
        }
        return ans;
    }
};