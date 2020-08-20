/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> list;
        ListNode* last = head;
        ListNode* front = head;
        if (!last || !last->next || !last->next->next) return;
        list.push(last);
        last = last->next;
        while (last) {
            list.push(last);
            last = last->next;
        }
        
        while (true) {
            ListNode* tmp = front->next;
            ListNode* back = list.top();
            back->next = tmp;
            front->next = back;
            list.pop();
            if (front == list.top() || front == back) {
                front->next->next = nullptr;
                break;
            }
            front = tmp;
        }
    }
};
