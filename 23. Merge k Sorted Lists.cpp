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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *cur;
        if(!list1&&!list2) return list1;
        else if(!list1) return list2;
        else if(!list2) return list1;
        else{
            if(list1->val<list2->val){
                head = list1;
                list1 = list1->next;
            }else{
                head = list2;
                list2 = list2->next;
            }
            cur = head;
            while(list1&&list2){
                if(list1->val<list2->val){
                    cur->next = list1;
                    cur = list1;
                    list1 = list1->next;
                }else{
                    cur->next = list2;
                    cur = list2;
                    list2 = list2->next;
                }
            }
        }
        while(list1){
            cur->next = list1;
            cur = list1;
            list1 = list1->next;
        }
        while(list2){
            cur->next = list2;
            cur = list2;
            list2 = list2->next;
        }
        return head;
    }
    ListNode* divide(vector<ListNode*>& lists, int left, int right){
        if(left==right) return lists[left];
        int mid = (left+right)>>1;
        ListNode* l1 = divide(lists, left, mid);
        ListNode* l2 = divide(lists, mid+1, right);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }
};
