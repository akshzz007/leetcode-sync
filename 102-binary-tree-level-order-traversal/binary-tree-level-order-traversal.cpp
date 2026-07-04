class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        // Final answer store karega.
        // Har level ek alag vector me store hoga.
        vector<vector<int>> ans;

        // Agar tree hi empty hai to kuch traverse nahi karna.
        if(root == NULL)
            return ans;

        // BFS ke liye queue use hoti hai.
        // Queue me TreeNode* store kar rahe hain (nodes ke addresses).
        queue<TreeNode*> q;

        // Traversal hamesha root se start hota hai.
        q.push(root);

        // Jab tak queue me nodes bache hain tab tak process karo.
        while(!q.empty()) {

            // IMPORTANT:
            // Current level me jitne nodes hain unki count store kar lo.
            // Isi wajah se ek hi level ke nodes process honge.
            int size = q.size();

            // Is vector me current level ki values store hongi.
            vector<int> level;

            // Sirf current level ke nodes process karo.
            for(int i = 0; i < size; i++) {

                // Queue ke front wala node uthao.
                TreeNode* node = q.front();

                // Node process ho gaya, queue se hata do.
                q.pop();

                // Left child exist karta hai to next level ke liye queue me daal do.
                if(node->left != NULL)
                    q.push(node->left);

                // Right child bhi next level ke liye queue me daal do.
                if(node->right != NULL)
                    q.push(node->right);

                // Current node ki value current level me add karo.
                level.push_back(node->val);
            }

            // Pura level process ho gaya.
            // Ab ise final answer me add kar do.
            ans.push_back(level);
        }

        // Sare levels traverse ho gaye.
        return ans;
    }
};