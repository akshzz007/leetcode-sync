class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<long long> seen;

        for(int i = 0; i < nums.size() - 1; i++) {
            long long sum = (long long)nums[i] + nums[i + 1];

            if(seen.count(sum)) 
                return true;

            seen.insert(sum);
        }

        return false;
    }
};
