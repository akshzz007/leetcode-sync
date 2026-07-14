class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base Case
        // Agar tree khatam ho gaya (NULL mil gaya)
        // ya current node hi p ya q hai,
        // to isi node ko return kar do.

        if(root == NULL || root == p || root == q)
            return root;

        // Left subtree me LCA dhoondo
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Right subtree me LCA dhoondo
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Agar left side se kuch nahi mila
        // to answer right side me hoga.

        if(left == NULL)
            return right;

        // Agar right side se kuch nahi mila
        // to answer left side me hoga.

        else if(right == NULL)
            return left;

        // Agar dono side se node mil gayi
        // Matlab ek node left me thi
        // aur dusri right me.
        // Isliye current root hi LCA hai.

        else
            return root;
    }
};