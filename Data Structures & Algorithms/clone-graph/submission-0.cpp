/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*>mp; //check for uniqueness
        queue<Node*>q;
        mp[node] = new Node(node->val);
        Node* head = mp[node];
        q.push(node);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            // neighbors of x
            for(auto v : x->neighbors){
                if(mp.count(v) == 0){
                    mp[v] = new Node(v->val);
                    q.push(v);
                }
                mp[x]->neighbors.push_back(mp[v]); //add the neighbor to the parent
            }
        }
        return head;
    }
};
