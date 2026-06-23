class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<vector<int>> inc(m + 1, vector<int>(1, 0));
        vector<vector<int>> dec(m + 1, vector<int>(1, 0));

        // dp for length=2

        vector<int> curInc(m + 1, 0);
        vector<int> curDec(m + 1, 0);

        for (int a = 1; a <= m; a++) {

            curInc[a] = a - 1;      // smaller values before a

            curDec[a] = m - a;      // greater values before a
        }

        // If n=2 hota to yahi answer hota,
        // but constraints say n>=3.

        for (int len = 3; len <= n; len++) {

            vector<int> prefixInc(m + 1, 0);
            vector<int> prefixDec(m + 1, 0);

            for (int i = 1; i <= m; i++) {

                prefixInc[i] =
                    (prefixInc[i - 1] + curInc[i]) % MOD;

                prefixDec[i] =
                    (prefixDec[i - 1] + curDec[i]) % MOD;
            }

            vector<int> nextInc(m + 1, 0);
            vector<int> nextDec(m + 1, 0);

            for (int y = 1; y <= m; y++) {

                // previous move decreasing
                // now increasing => choose smaller values

                nextInc[y] = prefixDec[y - 1];

                // previous move increasing
                // now decreasing => choose greater values

                nextDec[y] =
                    (prefixInc[m] - prefixInc[y] + MOD) % MOD;
            }

            curInc = move(nextInc);

            curDec = move(nextDec);
        }

        long long ans = 0;

        for (int i = 1; i <= m; i++) {

            ans += curInc[i];

            ans += curDec[i];

            ans %= MOD;
        }

        return ans;
    }
};