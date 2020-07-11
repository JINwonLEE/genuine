/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        stack<Node*> stack;
        Node* current = head;
        while (current) {
            if (current->child) {
                if (current->next) stack.push(current->next);
                current->next = current->child;
                current->next->prev = current;
                current->child = nullptr;
            }
            
            if (!current->next && !stack.empty()) {
                Node* sib = stack.top();
                stack.pop();
                current->next = sib;
                current->next->prev = current;
            }
            current = current->next;
        }

        return head;
    }
};
