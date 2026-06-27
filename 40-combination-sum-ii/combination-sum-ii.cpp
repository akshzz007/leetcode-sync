class Solution {
public:

    void findCombination(int target, int ind, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // Pruning
            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);

            findCombination(target - arr[i], i + 1, arr, ans, ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(target, 0, candidates, ans, ds);

        return ans;
    }
};