class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        // dp[i] = number of distinct subsequences
        // using first i characters, including empty subsequence
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;  // empty subsequence
        
        // Last position where each character appeared
        vector<int> last(26, -1);
        
        for (int i = 1; i <= s.size(); i++) {
            int ch = s[i - 1] - 'a';
            
            // Every old subsequence can either:
            // 1. not take s[i-1]
            // 2. take s[i-1]
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            // But if this character appeared before,
            // some subsequences are duplicated.
            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;
            }
            
            last[ch] = i;
        }
        
        // Remove empty subsequence
        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};