class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;

        vector<vector<int>> cost(m, vector<int>(n, INF));
        cost[m-1][n-1] = 0;

        // all cells sorted by value
        vector<array<int,3>> cells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.push_back({grid[i][j], i, j});
        sort(cells.begin(), cells.end());

        for (int t = 0; t <= k; t++) {

            // 1️⃣ normal DP (same layer)
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i + 1 < m)
                        cost[i][j] = min(cost[i][j],
                                          cost[i + 1][j] + grid[i + 1][j]);
                    if (j + 1 < n)
                        cost[i][j] = min(cost[i][j],
                                          cost[i][j + 1] + grid[i][j + 1]);
                }
            }

            if (t == k) break; // no more teleports allowed

            // 2️⃣ teleport DP → next layer
            vector<vector<int>> nextCost = cost;

            int best = INF;
            int ptr = 0;
            for (auto &[val, x, y] : cells) {
                while (ptr < cells.size() && cells[ptr][0] <= val) {
                    best = min(best,
                               cost[cells[ptr][1]][cells[ptr][2]]);
                    ptr++;
                }
                nextCost[x][y] = min(nextCost[x][y], best);
            }

            cost = nextCost;
        }

        return cost[0][0];
    }
};
