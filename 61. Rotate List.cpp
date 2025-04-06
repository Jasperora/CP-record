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
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head) return nullptr;
            int len = 0;
            ListNode* cur = head;
            while(cur){
                if(!cur->next){
                    cur->next = head;
                    cur = nullptr;
                }else{
                    cur = cur->next;
                }
                ++len;
            }
    
            k %= len;
    
            int stepToNewHead = len - k - 1;
            cur = head;
            while(stepToNewHead--){
                cur = cur->next;
            }
            ListNode* newHead = cur->next;
            cur->next = nullptr;
            return newHead;
        }
    };