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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return getNumber(root, 0);
    }
    
    int getNumber(TreeNode* current, int parent_sum) {
        if (!current) {
            return 0;
        }

        if (!current->left && !current->right) {
            return current->val + 10 * parent_sum;
        } else {
            return getNumber(current->left, current->val + 10 * parent_sum) + 
                getNumber(current->right, current->val + 10 * parent_sum);
        }
    }
};
