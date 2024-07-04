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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        temp = temp->next;
        int sum = 0;
        while(temp) {
            if (temp->val == 0) {
                curr->next = new ListNode(sum);
                sum = 0;
                curr = curr->next;
                temp = temp->next;
            } else {
                sum += temp->val;
                temp = temp->next;
            }
        }
        
        return ans->next;
    }
};