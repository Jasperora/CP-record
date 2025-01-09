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
    bool ret = false;
    set<ListNode*> visited;
    void dfs(ListNode* head){
        if(!head->next){
            return;
        }else if(visited.count(head->next)){
            ret = true;
            return;
        }else{
            visited.insert(head);
            dfs(head->next);
        }
    }
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        dfs(head);
        return ret;        
    }
};
