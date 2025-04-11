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
        ListNode* sort(ListNode* head){
            if(!head || !head->next) return head;
            ListNode* cur = head;
            int list_len = 0;
            while(cur){
                ++list_len;
                cur = cur->next;
            }
            ListNode *firstHeadEnd = head, *secondHead = head;
            int first_len = (list_len >> 1) - 1;
            for(int i = 0; i < first_len; ++i){
                firstHeadEnd = firstHeadEnd->next;
            }
            secondHead = firstHeadEnd->next;
            firstHeadEnd->next = nullptr;
            ListNode* l1 = sort(head);
            ListNode* l2 = sort(secondHead);
            ListNode* dummy = new ListNode(0);
            cur = dummy;
            while(l1 && l2){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            if(l1) cur->next = l1;
            else if(l2) cur->next = l2;
            return dummy->next;
        }
        ListNode* sortList(ListNode* head) {
            return sort(head);
        }
    };