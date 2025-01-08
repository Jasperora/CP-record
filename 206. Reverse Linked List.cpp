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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        vector<ListNode*> list;
        ListNode* ret;
        while(head){
            list.push_back(head);
            ListNode* next_head = head->next;
            head->next = nullptr;
            head = next_head;
        }
        ret = list[list.size()-1];
        for(int i = list.size()-1; i > 0; --i){
            list[i]->next = list[i-1];
        }
        return ret;
    }
    ListNode* otherReverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
