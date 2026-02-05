class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                result[i] = 0;
            }
            else if(nums[i] > 0) {
                int newIndex = (i + nums[i]) % n;
                result[i] = nums[newIndex];
            }
            else { // nums[i] < 0
                int steps = (-nums[i]) % n;
                int newIndex = (i - steps + n) % n;
                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};
