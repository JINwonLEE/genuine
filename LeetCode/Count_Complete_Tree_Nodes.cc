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
#include <cmath>

class Solution {
public:
    int countNodes(TreeNode* root) {
        int height = 0;
        TreeNode* current = root;

        while (current) {
            current = current->left;
            height++;
        }
        int complete = pow(2, height - 1) - 1;

        int count = nodeCount(root, 0, height - 1);
        
        return count + complete;
    }
    
    int nodeCount(TreeNode* current, int current_height, int height) {
        
        if (!current) {
            return 0;
        }
        
        if (height == 0) {
            return 1;
        }
        
        if (current_height == height - 1) {
            int left_num = current->left != nullptr;
            int right_num = current->right != nullptr;
            return left_num + right_num;
        } else {
            return nodeCount(current->left, current_height + 1, height) +
                nodeCount(current->right, current_height + 1, height);
        }
    }
};
