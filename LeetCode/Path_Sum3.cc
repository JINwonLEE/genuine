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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSum(root->right, sum) + pathSum(root->left, sum) + findSum(root, sum);
    }
    
    int findSum(TreeNode* current, int sum) {
        if (!current) return 0;
        int result = 0;
        if (current->val == sum) result++;
        return result + findSum(current->left, sum - current->val) 
            + findSum(current->right, sum - current->val);
    }
};
