class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for(int i=1;i<points.size();i++) {
            total += minDist(points[i-1][0], points[i-1][1], points[i][0], points[i][1]);
        }

        return total;
    }

    int minDist(int x1, int y1, int x2, int y2) {
        return max(abs(x2-x1), abs(y2-y1));   
    }
};