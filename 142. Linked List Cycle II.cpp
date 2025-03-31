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
        ListNode *detectCycle(ListNode *head) {
            if(!head) return nullptr;
            ListNode *slow = head, *fast = head;
            slow = slow->next;
            if(fast->next) fast = fast->next->next;
            else return nullptr;
            while(fast && fast!=slow){
                if(fast->next) fast = fast->next->next;
                else return nullptr;
                slow = slow->next;
            }
            if(!fast) return nullptr;
            ListNode* slow2 = head;
            while(slow!=slow2){
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
    };