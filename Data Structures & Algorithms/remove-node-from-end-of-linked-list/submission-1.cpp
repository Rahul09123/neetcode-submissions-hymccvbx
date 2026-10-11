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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // calculate the length of the ll
        if (head->next == nullptr && n == 1) {
            return nullptr;
        }
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }
        // delete the (n-len)'th node
        int pos = len - n;
        curr = head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        if (pos == 0) {  // removes the first node
            head = head -> next;
            return head;
        } else {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return head;
        }
    }
};
