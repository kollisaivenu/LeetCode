class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int>freq;
        for(int i=0;i<hand.size();i++) {
            freq[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        for(int i=0;i<hand.size();i++) {
            if(freq[hand[i]] > 0) {
                int start = hand[i];
                int next = start+1;
                int f = freq[hand[i]];
                freq[start] = 0;
                for(int j=1;j<groupSize;j++) {
                    if(freq[next] >= f) {
                        freq[next] -= f;
                    } else {
                        cout<<start<<"\n";
                        cout<<next<<"\n";
                        return false;
                    }
                    next++;
                }
            }
        }

        return true;
        
    }
};