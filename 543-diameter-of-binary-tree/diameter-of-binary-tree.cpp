class Solution {
public:

    // Main function jo LeetCode call karega
    int diameterOfBinaryTree(TreeNode* root) {

        // Initially diameter 0 maan lete hain
        int diameter = 0;

        // Height calculate karte waqt hi diameter bhi update hoga
        height(root, diameter);

        // Final maximum diameter return kar do
        return diameter;
    }

private:

    // Ye function current node ki height return karega
    // aur reference (&) ki wajah se original diameter update karega
    int height(TreeNode* node, int &diameter) {

        // Agar node NULL hai to uski height 0 hogi
        if (node == NULL)
            return 0;

        // Left subtree ki height nikaalo
        int lh = height(node->left, diameter);

        // Right subtree ki height nikaalo
        int rh = height(node->right, diameter);

        // Current node ke through longest path = left height + right height
        // Agar ye purane diameter se bada hai to update kar do
        diameter = max(diameter, lh + rh);

        // Height = 1 (current node) + max(left height, right height)
        return 1 + max(lh, rh);
    }
};