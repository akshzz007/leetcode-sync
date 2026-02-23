class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.length();
        if (n < k) return false;

        unordered_set<int> seen;
        int curr = 0;
        int mask = (1 << k) - 1;

        for (int i = 0; i < n; i++) {
            
            // Left shift and add new bit
            curr = ((curr << 1) & mask) | (s[i] - '0');
            
            if (i >= k - 1) {
                seen.insert(curr);
            }
        }

        return seen.size() == (1 << k);
    }
};