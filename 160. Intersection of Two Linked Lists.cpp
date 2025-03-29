/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(!headA || !headB) return nullptr;
            ListNode *ptrA = headA, *ptrB = headB;
            while(ptrA != ptrB){
                if(!ptrA) ptrA = headB;
                else ptrA = ptrA->next;
                if(!ptrB) ptrB = headA;
                else ptrB = ptrB->next;
            }
            return ptrA;
        }
    };