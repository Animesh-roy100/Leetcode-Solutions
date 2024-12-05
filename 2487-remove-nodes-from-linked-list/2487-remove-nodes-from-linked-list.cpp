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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *curr = head;
        while(curr!=NULL){
            stk.push(curr);
            curr = curr->next;
        }
        
        curr = stk.top();
        stk.pop();
        int maxVal = curr->val;
        ListNode *ans = new ListNode(maxVal);
        
        while(!stk.empty()) {
            curr = stk.top();
            stk.pop();
            
            if(maxVal > curr->val) continue;
            else {
                maxVal = curr->val;
                ListNode *newNode = new ListNode(curr->val);
                newNode->next = ans;
                ans = newNode;
            }
        }
        
        return ans;
    }
};