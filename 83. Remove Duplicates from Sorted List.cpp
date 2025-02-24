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
        ListNode* deleteDuplicates(ListNode* head) {
            if(!head||!head->next) return head;
            ListNode* ret = head;
            ListNode *i, *j;
            i = head;
            j = head->next;
            while(j){
                if(i->val==j->val){
                    while(j && j->val==i->val){
                        j = j->next;
                    }
                    if(!j){
                        i->next = nullptr;
                        return ret;
                    }else{
                        i->next = j;
                        i = j;
                        j = j->next;
                    }
                    
                }else{
                    i = i->next;
                    j = j->next;
                }
            }
            return ret;
        }
    };