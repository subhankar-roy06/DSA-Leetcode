
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        // Find length and last node
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        // Reduce unnecessary rotations
        k %= len;
        if (k == 0){
            return head;
        }
        // Make the list circular
        tail->next = head;
        // Find the new tail
        int steps = len - k - 1;
        ListNode* newTail = head;
        while (steps--) {
            newTail = newTail->next;
        }
        // New head is next of new tail
        ListNode* newHead = newTail->next;
        // Break the circle
        newTail->next = nullptr;
        return newHead;
    }
};