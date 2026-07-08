/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    // DFS function
    // root -> current node
    // level -> current node kis level pe hai
    // res -> final answer store karega
    void dfs(TreeNode* root, int level, vector<int>& res)
    {
        // Agar node NULL hai to aage kuch nahi karna
        if(root == NULL)
            return;

        // Agar is level pe pehli baar aaye hain
        // to current node ko answer me store kar do
        if(res.size() == level)
            res.push_back(root->val);

        // Sabse pehle RIGHT subtree visit karenge
        // Kyuki hume Right View chahiye
        dfs(root->right, level + 1, res);

        // Fir LEFT subtree visit karenge
        dfs(root->left, level + 1, res);
    }

public:
    vector<int> rightSideView(TreeNode* root) {

        // Final answer store karne ke liye vector
        vector<int> res;

        // DFS start karenge root se
        // Root level 0 pe hota hai
        dfs(root, 0, res);

        // Final answer return
        return res;
    }
};