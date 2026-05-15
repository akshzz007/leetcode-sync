class Solution {
public:

    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            // Minimum right side me
            if(nums[mid] > nums[high]) {

                low = mid + 1;
            }

            // Minimum left side me including mid
            else {

                high = mid;
            }
        }

        return nums[low];
    }
};