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
    ListNode* getKthNode(ListNode* cur, int k){
        while(k-- && cur){
            cur = cur->next;
        }
        // cur would be nullptr if no k elements
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* group_prev = &dummy;
        while(true){
            ListNode* kth = getKthNode(group_prev, k);
            if(!kth) break;
            ListNode* next_group_head = kth->next;

            ListNode *prev = next_group_head, *curr = group_prev->next, *next;
            while(curr!=next_group_head){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            next = group_prev->next; // original first, current last node in the group
            // cout << "next: " << next->val << '\n';
            group_prev->next = kth;
            // cout << kth->val << '\n';
            group_prev = next;
        }
        return dummy.next;
    }
};
