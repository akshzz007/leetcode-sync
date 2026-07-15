class Solution {
public:

    int rangeSumBST(TreeNode* root, int low, int high) {

        // Base case
        if(root == NULL)
            return 0;

        // Root chhota hai low se
        // To left subtree me sab aur chhote honge
        // Sirf right explore karo
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        // Root bada hai high se
        // To right subtree me sab aur bade honge
        // Sirf left explore karo
        if(root->val > high)
            return rangeSumBST(root->left, low, high);

        // Root range ke andar hai
        // Isko add karo aur dono side explore karo
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};