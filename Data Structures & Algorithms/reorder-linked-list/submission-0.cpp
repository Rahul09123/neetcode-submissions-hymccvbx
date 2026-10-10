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
    ListNode* solve(ListNode* root,ListNode* curr){
        if(!curr){
            return root;
        }
        root = solve(root,curr->next);
        if(root == nullptr){
            return nullptr;
        }
        ListNode* temp = nullptr;
        if(root == curr || root->next == curr){
            curr->next = nullptr;
        }
        else{
            temp = root->next;
            root->next = curr;
            curr->next = temp;
        }
        return temp;
    }

    void reorderList(ListNode* head) {
        head = solve(head,head->next);
        
    }
};
