/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;

            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            copy->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next;
        }
        curr = head;
        Node* newHead = head ? head->next : nullptr;

        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            curr = curr->next;
        }

        return newHead;
    }
};
