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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while(head){
            ++size;
            head = head->next;
        }
        head = tmp;
        int cnt = size - n;
        if(cnt==0) return head->next;
        else if(cnt==size){
            if(size==2){
                head->next = nullptr;
                return head;
            }
            for(int i = 0; i < size-2; ++i){
                head = head->next;
            }
            head->next = nullptr;
            return tmp;
        }else{
            for(int i = 0; i < cnt-1; ++i){
                head = head->next;
            }
            head->next = head->next->next;
        }
        return tmp;
    }
};
