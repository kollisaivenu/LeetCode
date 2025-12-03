class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, long long>freq;

        for(int i=0;i<points.size();i++){
            freq[points[i][1]]++;
        }

        vector<long long>numOfLines;

        for(const auto& pair : freq){
            numOfLines.push_back(sumToN(pair.second-1));
        }

        long long initialSum = 0, ans=0;

        for(int i=0;i<numOfLines.size();i++){
            ans += initialSum*numOfLines[i];
            initialSum += numOfLines[i];
        }

        return ans%1000000007;
    }

    long long sumToN(long long n){
        return n*(n+1)/2;
    }
};