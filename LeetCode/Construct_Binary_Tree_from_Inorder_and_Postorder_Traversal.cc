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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* makeTree(vector<int>& inorder, int in_st, int in_en, vector<int>& postorder, 
                       int po_st, int po_en) {
        if (in_st > in_en || po_st > po_en) return nullptr;
        TreeNode* root = new TreeNode(postorder[po_en]);
        int index = in_st;
        while (inorder[index] != postorder[po_en]) index++;
        root->left = makeTree(inorder, in_st, index - 1, 
                              postorder, po_st, po_st + index - in_st - 1);
        root->right = makeTree(inorder, index + 1,  in_en, 
                               postorder, po_st + index - in_st, po_en - 1);
        return root;
    }
};
