/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> tmp;
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur == NULL && !q.empty()) {
                res.push_back(tmp);
                tmp.clear();
                q.push(NULL);
            } else if (cur != NULL) {
                tmp.push_back(cur->val);
                for (int i = 0; i < cur->children.size(); ++i) {
                    q.push(cur->children[i]);
                }
            } else {
                res.push_back(tmp);
                tmp.clear();
            }
        }
        
        return res;
    }
};
