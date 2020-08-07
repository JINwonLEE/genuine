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
struct Node {
    TreeNode* tree_node;
    int ver_pos;
};
class Solution {
public:
    map<int, vector<int>> coord_map;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<Node> q;
        q.push(Node{root, 0});
        while (!q.empty()) {
            int len = q.size();
            map<int, vector<int>> tmp_list;
            for (int i = 0; i < len; i++) {
                Node cur = q.front(); q.pop();
                if (cur.tree_node->left) q.push(Node{cur.tree_node->left, cur.ver_pos - 1});
                if (cur.tree_node->right) q.push(Node{cur.tree_node->right, cur.ver_pos + 1});
                tmp_list[cur.ver_pos].push_back(cur.tree_node->val);
            }
            map<int, vector<int>>::iterator it = tmp_list.begin();
            while (it != tmp_list.end()) {
                sort(it->second.begin(), it->second.end());
                for (auto ele : it->second)
                    coord_map[it->first].push_back(ele);
                it++;
            }
        }
        
        map<int, vector<int>>::iterator it = coord_map.begin();
        while (it != coord_map.end()) {
            result.push_back(it->second);
            it++;
        }
        return result;
    }
};
