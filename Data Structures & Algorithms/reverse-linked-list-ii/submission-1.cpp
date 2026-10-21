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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode dummy(0, head);
    ListNode* prevGroup = &dummy;

    // 1. Walk up to the node BEFORE 'left'
    for (int i = 0; i < left - 1; ++i) {
        prevGroup = prevGroup->next;
    }

    // 2. Identify boundary pointers
    ListNode* sublistHead = prevGroup->next; // Will become the tail of reversed sublist
    ListNode* curr = sublistHead;
    ListNode* prev = nullptr;

    // 3. Standard Linked List Reversal Logic
    for (int i = 0; i < right - left + 1; ++i) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // 4. Reconnect the boundaries
    // 'prev' is now the new head of the reversed sublist
    // 'curr' is now the node right after 'right'
    prevGroup->next = prev;        // Connect outer left to reversed head
    sublistHead->next = curr;     // Connect reversed tail to outer right

    return dummy.next;
}
};