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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
            ListNode* dummy = new ListNode();
            ListNode* cur = dummy;
            while(l1 && l2){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            if(l1) cur->next = l1;
            else if(l2) cur->next = l2;
            return dummy->next;
        }
        ListNode* divide(vector<ListNode*>& lists, int left, int right){
            if(left == right) return lists[left];
            else if(left > right) return nullptr;
            int mid = (left + right) >> 1;
            ListNode* l1 = divide(lists, left, mid);
            ListNode* l2 = divide(lists, mid + 1, right);
            return mergeTwoLists(l1, l2);
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size() == 0) return nullptr;
            return divide(lists, 0, lists.size() - 1);
        }
    };