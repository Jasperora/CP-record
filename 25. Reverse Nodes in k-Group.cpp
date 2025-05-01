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

// recursive
class Solution1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        int len = 0;
        ListNode* cur = head;
        while(cur){
            ++len;
            if(len == k)
                break;
            cur = cur->next;
        }
        if(len < k)
            return head;
        // k = 2
        // 1 -> 2 -> 3 -> 4 -> 5
        //     cur
        ListNode* nextHead = cur->next;
        ListNode *prev = dummy, *current = head;
        // dummy ->    1    ->  2  -> 3 -> 4 -> 5
        //  prev -> current -> next
        while(current != nextHead){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        dummy->next = cur;
        head->next = reverseKGroup(nextHead, k);
        return dummy->next;
    }
};
// traverse whole list, reverse k nodes at a time
class Solution2 {
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