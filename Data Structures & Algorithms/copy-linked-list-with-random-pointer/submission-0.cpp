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
        unordered_map<Node*,Node*>mp;
        Node* curr = head;
        mp[nullptr] = nullptr;
        Node* newHead = nullptr;
        while(curr){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;
            curr = curr->next;
        }
        curr = head;

        while(curr){
            if(!newHead){
                newHead = mp[curr];
            }
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }
        return newHead;
    }
};
