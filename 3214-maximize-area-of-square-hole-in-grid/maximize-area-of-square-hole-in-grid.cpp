class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        auto maxConsecutive = [&](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int maxLen = 1, curr = 1;

            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    curr++;
                } else {
                    curr = 1;
                }
                maxLen = max(maxLen, curr);
            }
            return maxLen;
        };

        int hMax = maxConsecutive(hBars);
        int vMax = maxConsecutive(vBars);

        int side = min(hMax + 1, vMax + 1);
        return side * side;
    }
};
