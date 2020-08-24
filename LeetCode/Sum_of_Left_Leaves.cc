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
    int sumOfLeftLeaves(TreeNode* root) {
        std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
        int sum = 0;
        if (!root || (!root->left && !root->right)) return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                if (!current->left->left && !current->left->right) {
                    sum += current->left->val;
                }
                queue.push(current->left);
            } 
            
            if (current->right) {
                queue.push(current->right);
            }
        }
        return sum;
    }
};
