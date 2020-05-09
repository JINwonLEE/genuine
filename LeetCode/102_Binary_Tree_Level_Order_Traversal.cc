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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root) {
            checkElements(root, 0, result);
        }
        
        return result;
    }
    
    void checkElements(TreeNode* currentNode, int depth, vector<vector<int>>& result) {
        if (result.size() < depth + 1) {
            vector<int> newDepthArray;
            result.push_back(newDepthArray);
        }
        
        result[depth].push_back(currentNode->val);
        if (currentNode->left) {
            checkElements(currentNode->left, depth + 1, result);
        }
        
        if (currentNode->right) {
            checkElements(currentNode->right, depth + 1, result);
        }
    }
    
};
