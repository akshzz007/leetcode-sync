class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = 0;

        // Har index ko starting point banao
        for (int i = 0; i < n; i++) {

            int cntTarget = 0; // Current subarray me target kitni baar aaya

            // Subarray ko i se j tak badhate jao
            for (int j = i; j < n; j++) {

                // Agar current element target hai to count badhao
                if (nums[j] == target)
                    cntTarget++;

                // Current subarray ki length
                int len = j - i + 1;

                // Majority condition:
                // target ki frequency length ke half se jyada honi chahiye
                if (2 * cntTarget > len)
                    ans++;
            }
        }

        return ans;
    }
};