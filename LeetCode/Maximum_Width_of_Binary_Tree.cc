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
struct Pos {
    TreeNode* node;
    long long pos;
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int length = 1;
        queue<Pos> queue;
        queue.push({root, 0});
        
        while (!queue.empty()) {
            int size = queue.size();
            long long start_pos = INT_MAX;
            long long offset = 0;
            long long end_pos = INT_MIN;
            for (int i = 0; i < size; i++) {
                Pos current = queue.front();
                queue.pop();
                if (start_pos == INT_MAX) {
                    offset = current.pos;
                    start_pos = 0;
                }
                if (end_pos < current.pos) {
                    end_pos = current.pos - offset;
                }
                if (current.node->left) {
                    queue.push({current.node->left, (current.pos - offset) * 2});
                }
                
                if (current.node->right) {
                    queue.push({current.node->right, (current.pos - offset) * 2 + 1});
                }
            }
            
            if (length < end_pos - start_pos + 1) {
                length = end_pos - start_pos + 1;
            }
        }
        return length;
    }
};
