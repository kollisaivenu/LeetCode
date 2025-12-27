class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>maxHeight(heights.size(), 0);

        maxHeight[heights.size()-1] = INT_MIN;

        for(int i=heights.size()-2;i>=0;i--){
            maxHeight[i] = max(heights[i+1], maxHeight[i+1]);
        }

        vector<int>ans;

        for(int i=0;i<heights.size();i++){
            if (heights[i] > maxHeight[i]) {
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};