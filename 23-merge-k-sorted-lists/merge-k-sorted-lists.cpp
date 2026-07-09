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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Put all node values into the min-heap
        for (ListNode* head : lists) {
            while (head != nullptr) {
                minHeap.push(head->val);
                head = head->next;
            }
        }

        // Dummy node
        ListNode* prev = new ListNode(0);
        ListNode* temp = prev;

        // Create the merged linked list
        while (!minHeap.empty()) {
            temp->next = new ListNode(minHeap.top());
            minHeap.pop();
            temp = temp->next;
        }

        return prev->next;
    }
};