class Solution {
public:

    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos,
             int prev1,
             int prev2,
             int tight,
             int started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prev1][prev2][tight][started])
            return dp[pos][prev1][prev2][tight][started];

        vis[pos][prev1][prev2][tight][started] = true;

        Node ans = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt =
                    dfs(pos + 1,
                        10,
                        10,
                        ntight,
                        0);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }
            else {

                Node nxt;

                if (!started) {

                    nxt =
                        dfs(pos + 1,
                            d,
                            10,
                            ntight,
                            1);

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav;
                }
                else {

                    int add = 0;

                    if (prev2 != 10) {

                        if ((prev1 > prev2 && prev1 > d) ||
                            (prev1 < prev2 && prev1 < d))
                            add = 1;
                    }

                    nxt =
                        dfs(pos + 1,
                            d,
                            prev1,
                            ntight,
                            1);

                    ans.cnt += nxt.cnt;

                    ans.wav += nxt.wav +
                               1LL * add * nxt.cnt;
                }
            }
        }

        return dp[pos][prev1][prev2][tight][started] = ans;
    }

    long long solve(long long x) {

        if (x <= 0)
            return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 1, 0).wav;
    }

    long long totalWaviness(long long num1,
                            long long num2) {

        return solve(num2) -
               solve(num1 - 1);
    }
};