class Solution {
public:
    bool isGood(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.back();

        // size should be n+1
        if(nums.size() != n + 1)
            return false;

        // check 1 to n-1
        for(int i = 0; i < n-1; i++) {

            if(nums[i] != i + 1)
                return false;
        }

        // last two elements should be n
        if(nums[n-1] != n || nums[n] != n)
            return false;

        return true;
    }
};