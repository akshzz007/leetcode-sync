class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        // 1️⃣ Strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1 || i == n) return false;

        // 2️⃣ Strictly decreasing
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == n || nums[i - 1] >= nums[i - 2]) return false;

        // 3️⃣ Strictly increasing again
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        return i == n;
    }
};
