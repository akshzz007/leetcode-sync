/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), right(right), left(left) {}
 * };
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> ans;          // Har level ka average store karega

        if(root == NULL)
            return ans;              // Agar tree empty hai to empty vector return

        queue<TreeNode*> q;
        q.push(root);                // BFS start root se

        while(!q.empty()) {

            int size = q.size();     // Current level ke total nodes
            long long sum = 0;       // Current level ka sum

            // Current level ke saare nodes process karo
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front(); // Front node lo
                q.pop();                    // Queue se remove karo

                sum += node->val;           // Node ki value sum me add karo

                // Left child hai to queue me add karo
                if(node->left)
                    q.push(node->left);

                // Right child hai to queue me add karo
                if(node->right)
                    q.push(node->right);
            }

            // Current level ka average answer me store karo
            ans.push_back((double)sum / size);
        }

        return ans;                  // Final answer return
    }
};