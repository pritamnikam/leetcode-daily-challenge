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
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // create a clone and add to a map
        Node* clone = new Node(head->val);
        map[head] = clone;
        
        // recurrsively clone the remaining list
        clone->next = copyRandomList(head->next);
        
        // adjust the random node in new list
        clone->random = map[head->random];

        return clone;
    }
};
