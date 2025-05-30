class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>maxLeftHeight(height.size(), -1);
        vector<int>maxRightHeight(height.size(), -1);

        for(int i=1;i<maxLeftHeight.size();i++){
            maxLeftHeight[i] = max(maxLeftHeight[i-1], height[i-1]);
        }

        for(int i=maxRightHeight.size()-2;i>=0;i--){
            maxRightHeight[i] = max(maxRightHeight[i+1], height[i+1]);
        }

        int water = 0;
        for(int i=1;i<height.size()-1;i++){
            water += max(min(maxLeftHeight[i], maxRightHeight[i]) - height[i], 0);
        }

        return water;
    }
};