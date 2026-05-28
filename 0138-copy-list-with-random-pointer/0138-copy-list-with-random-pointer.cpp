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
        unordered_map<Node*, Node*>mapping;
        Node* curr = head;
        while(curr) {
            if(!mapping.contains(curr)) {
                mapping[curr] = new Node(curr->val);
            }

            if(curr->random != NULL && mapping.contains(curr->random)) {
                mapping[curr->random] = new Node(curr->random->val); 
            }
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            mapping[curr]->next = mapping[curr->next];
            if(curr->random != NULL) {
                mapping[curr]->random = mapping[curr->random];
            } else {
                mapping[curr]->random = NULL;
            }
            curr = curr->next;
        }

        return mapping[head];
        
    }
};