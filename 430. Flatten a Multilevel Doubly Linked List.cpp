/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    public:
        Node* flatten(Node* head) {
            Node* cur = head;
            while(cur){
                if(cur->child){
                    Node* originalNext = cur->next;
                    Node* flattenHead = flatten(cur->child);
    
                    cur->next = flattenHead;
                    cur->child = nullptr;
                    flattenHead->prev = cur;
                    
                    while(cur->next){
                        cur = cur->next;
                    }
                    cur->next = originalNext;
                    if(originalNext)
                        originalNext->prev = cur;
    
                    cur = originalNext;
                }else{
                    cur = cur->next;
                }
            }
            return head;
        }
    };