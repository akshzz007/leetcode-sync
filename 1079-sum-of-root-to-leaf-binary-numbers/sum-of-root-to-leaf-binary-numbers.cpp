class Solution {
public:
    
    int dfs(TreeNode* node, int curr) {
        if(node == NULL) return 0;

        // Build binary number
        curr = (curr << 1) + node->val;

        // If leaf node → return this number
        if(node->left == NULL && node->right == NULL)
            return curr;

        // Recurse left and right
        return dfs(node->left, curr) + dfs(node->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};