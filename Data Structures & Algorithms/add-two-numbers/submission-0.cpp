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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nn = new ListNode(-1);
        ListNode* temp = nn;
        int carry = 0, sum = 0;
        while(l1 || l2 || carry) {
            sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum  = sum % 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = temp->next;
        }
        return nn->next;
    }
};
