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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* curr = head;
        while(curr != nullptr) {
            n++;
            curr = curr->next;
        }
        int size = n/k;
        int extra = n%k;
        vector<ListNode*> ans(k);
        curr = head;
        
        for(int i=0; i<k; i++) {
            if(curr == nullptr) break;
            ans[i] = curr;
            ListNode* prev = nullptr;
            for(int j=0; j<size; j++) {
                prev = curr;
                curr = curr->next;
            }
            if(extra>0) {
                prev = curr;
                curr = curr->next;
                extra--;
            }
            prev->next = nullptr;
        }
        
        return ans;
    }
};