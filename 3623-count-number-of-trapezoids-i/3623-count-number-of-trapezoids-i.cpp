class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, long long>freq;

        for(int i=0;i<points.size();i++){
            freq[points[i][1]]++;
        }

        long long initialSum = 0, ans=0;
        for(const auto& pair : freq){
            long long sum = sumToN(pair.second-1);
            ans += initialSum*sum;
            initialSum += sum;
        }

        return ans%1000000007;
    }

    long long sumToN(long long n){
        return n*(n+1)/2;
    }
};