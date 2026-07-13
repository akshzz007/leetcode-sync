class Solution {
public:
    int sum;   // Ye variable pura recursion ke dauran total sum store karega.

    // DFS function
    void dfs(TreeNode* node) {

        // Agar left child exist karta hai
        if(node->left != nullptr){

            // Check karo ki left child leaf hai ya nahi
            // Matlab uske left aur right dono NULL hone chahiye.
            if(node->left->left == nullptr &&
               node->left->right == nullptr)
            {
                // Left leaf mil gaya to uski value add kar do.
                sum += node->left->val;
            }

            // Left subtree explore karo.
            dfs(node->left);
        }

        // Agar right child exist karta hai
        if(node->right != nullptr){

            // Right subtree explore karo.
            dfs(node->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {

        // Har test case ke liye sum ko reset karna zaroori hai.
        sum = 0;

        // Agar tree empty hai
        if(root == nullptr)
            return 0;

        // DFS start karo root se.
        dfs(root);

        // Final answer return.
        return sum;
    }
};