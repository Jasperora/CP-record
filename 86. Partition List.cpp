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
        ListNode* partition(ListNode* head, int x) {
            ListNode* left = new ListNode(0);
            ListNode* right = new ListNode(0);
            ListNode* leftCur = left;
            ListNode* rightCur = right;
            ListNode* cur = head;
            while(cur){
                ListNode* newNode = new ListNode(cur->val);
                if(cur->val < x){
                    leftCur->next = newNode;
                    leftCur = leftCur->next;
                }else{
                    rightCur->next = newNode;
                    rightCur = rightCur->next;
                }
                cur = cur->next;
            }
            leftCur->next = right->next;
            return left->next;
        }
    };