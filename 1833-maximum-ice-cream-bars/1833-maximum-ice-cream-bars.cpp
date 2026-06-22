class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int, int>freq;
        int count = 0;
        bool cont = true;
        for(int i=0;i<costs.size();i++) {
            freq[costs[i]]++;
        }

        for(auto p: freq) {
            for(int j=1;j<=p.second;j++) {
                if(p.first <= coins) {
                    count++;
                    coins -= p.first;
                } else {
                    cont = false;
                    break;
                }
            }

            if(!cont) {
                break;
            }
        }

        return count;
        
    }
};