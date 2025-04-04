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
        ListNode* middleNode(ListNode* head) {
            ListNode* slow, *fast;
            slow = head;
            fast = head->next;
            while(fast){
                if(fast->next) fast = fast->next->next;
                else fast = nullptr;
                slow = slow->next;
            }
            return slow;
        }
    };