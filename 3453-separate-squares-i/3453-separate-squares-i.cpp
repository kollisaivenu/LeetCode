class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double max_y = 0, total_area = 0;

        for(int i=0;i<squares.size();i++) {
            int y = squares[i][1];
            int l = squares[i][2];
            total_area += (double)l*l;
            max_y = max(max_y, (double)(y+l));
        }

        double low = 0;
        double high = max_y;
        double ans;

        while(abs(high-low) > 1e-5) {
            double mid = (low + high)/2;

            if(check(mid, squares, total_area)) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }

        return ans;
    }

    bool check(double limit_y, vector<vector<int>>&squares, double total_area) {
        double area = 0;

        for(int i=0;i<squares.size();i++) {
            int y = squares[i][1], l = squares[i][2];

            if(y < limit_y) {
                area += l*min(limit_y - y, (double)l);
            }
        }

        return area >= total_area/2;
    }
};