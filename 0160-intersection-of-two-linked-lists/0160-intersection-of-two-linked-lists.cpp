/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> umap;
        
        while(headA != nullptr) {
            umap[headA]++;
            headA = headA->next;
        }
        
        while(headB != nullptr) {
            if(umap[headB] > 0) {
                return headB;
            }
            headB = headB->next;
        }
        
        return nullptr;
    }
};