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
        ListNode* merge(ListNode* l1, ListNode* l2){
            if(!l1 && !l2) return nullptr;
            if(!l1) return l2;
            if(!l2) return l1;
            if(l1->val < l2->val){
                ListNode* tmp = l1->next;
                l1->next = merge(tmp, l2);
                return l1;
            }else{
                ListNode* tmp = l2->next;
                l2->next = merge(tmp, l1);
                return l2;
            }
    
        }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            return merge(list1, list2);
        }
        ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
            ListNode dummy = ListNode(0);
            ListNode* tail = &dummy;
            while(list1 && list2){
                if(list1->val < list2->val){
                    tail->next = list1;
                    list1 = list1->next;
                }else{
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }
            if(list1) tail->next = list1;
            if(list2) tail->next = list2;
            return dummy.next;
        }
    };