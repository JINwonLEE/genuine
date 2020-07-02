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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> current_level_queue;
        int level = 0;
        if (!root) {
            return result;
        }
        
        current_level_queue.push(root);
        while (!current_level_queue.empty()) {
            int len_current_level = current_level_queue.size();
            vector<int> current_level;
            for (int i = 0; i < len_current_level; i++) {
                TreeNode* node = current_level_queue.front();
                current_level.push_back(node->val);
                current_level_queue.pop();
                if (node->left) current_level_queue.push(node->left);
                if (node->right) current_level_queue.push(node->right);
            }
            result.push_back(current_level);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
