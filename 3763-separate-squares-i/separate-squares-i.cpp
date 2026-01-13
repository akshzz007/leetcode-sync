class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0.0, high = 1e9;
        
        auto areaDiff = [&](double mid) {
            double below = 0.0, above = 0.0;
            
            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;
                
                if (mid <= y) {
                    // Entire square above
                    above += l * l;
                } 
                else if (mid >= top) {
                    // Entire square below
                    below += l * l;
                } 
                else {
                    // Line cuts the square
                    double hBelow = mid - y;
                    below += hBelow * l;
                    above += (l - hBelow) * l;
                }
            }
            return below - above;
        };
        
        // Binary search
        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2.0;
            if (areaDiff(mid) < 0)
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};
