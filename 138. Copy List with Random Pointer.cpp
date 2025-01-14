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
        Node* ret = new Node(0);
        Node* cur = ret;
        Node* tmp = head;
        map<Node*, Node*> m;

        Node* head2 = head;
        while(head){
            cur->next = new Node(head->val);
            m[head] = cur->next;
            cur = cur->next;
            head = head->next;
        }
        while(head2){
            m[head2]->random = m[head2->random];
            head2 = head2->next;
        }
        return ret->next;
    }
};
