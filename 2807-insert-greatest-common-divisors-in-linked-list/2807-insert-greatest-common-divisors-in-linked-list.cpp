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
private:
    int gcd(int a, int b) {
        if (a == b) return a;
        if (a > b) return gcd(a-b, a);
        return gcd(a, b-a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* curr = head;
        
        while(curr->next != nullptr) {            
            int gcdVal = gcd(curr->val, curr->next->val);
            
            ListNode* newNode = new ListNode(gcdVal);
            newNode->next = curr->next;
            curr->next = newNode;
            
            curr = newNode->next;
        }
        
        return head;
    }
};