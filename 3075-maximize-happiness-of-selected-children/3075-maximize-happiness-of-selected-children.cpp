class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;

        for(int i=0;i<happiness.size();i++){
            pq.push(happiness[i]);
        }
        long long h = 0;
        int s = 0;
        while(k){
            h += max(pq.top()-s,0);
            pq.pop();
            s++;
            k--;
        }
        return h;
    }
};