class Solution {
public:

    int findIndex(vector<int>& nums, int target, bool findFirst) {

        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                ans = mid;

                if (findFirst) {
                    high = mid - 1;   // search left side
                } else {
                    low = mid + 1;    // search right side
                }

            }
            else if (nums[mid] < target) {

                low = mid + 1;

            }
            else {

                high = mid - 1;

            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findIndex(nums, target, true);

        if (first == -1) {
            return {-1, -1};
        }

        int last = findIndex(nums, target, false);

        return {first, last};
    }
};