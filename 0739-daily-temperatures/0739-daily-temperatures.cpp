class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(), 0);
        stack<pair<int, int>>stk;

        for(int i=0;i<temperatures.size();i++) {
            if(stk.size() == 0) {
                stk.push(make_pair(temperatures[i], i));
            } else if(stk.top().first < temperatures[i]) {
                while(!stk.empty() && stk.top().first < temperatures[i]) {
                    ans[stk.top().second] = i - stk.top().second;
                    stk.pop();
                }
                stk.push(make_pair(temperatures[i], i));
            } else {
                stk.push(make_pair(temperatures[i], i));
            }
        }

        return ans;
    }
};