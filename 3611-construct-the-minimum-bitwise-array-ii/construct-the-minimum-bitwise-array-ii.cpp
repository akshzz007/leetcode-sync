class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            // if n is even, impossible
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            int k = 0;
            int temp = n;

            // count trailing 1s
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            // clear the highest bit among trailing 1s
            int x = n ^ (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};
