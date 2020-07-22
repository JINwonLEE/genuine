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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        bool zigzag = false;
        
        while (!queue.empty()) {
            int size_of_level = queue.size();
            vector<int> level_list;
            for (int i = 0; i < size_of_level; i++) {
                TreeNode* curr;
                curr = queue.front();
                queue.pop();
                if (curr->left) queue.push(curr->left);
                if (curr->right) queue.push(curr->right);      
                level_list.push_back(curr->val);
            }
            if (zigzag) reverse(level_list.begin(), level_list.end());
            zigzag = zigzag ^ 0x1;
            result.push_back(level_list);
        }
        return result;
        
    }
};
