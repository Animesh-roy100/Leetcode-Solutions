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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        ListNode* curr = head;
        int row=0, col=0;
        while(curr != nullptr) {
            while(curr != nullptr and col<n and ans[row][col] == -1) {
                ans[row][col] = curr->val;
                curr = curr->next;
                col++;
            }
            row++;
            col--;

            while(curr != nullptr and row<m and ans[row][col] == -1) {
                ans[row][col] = curr->val;
                curr = curr->next;
                row++;
            }
            row--;
            col--;

            while(curr != nullptr and col>=0 and ans[row][col] == -1) {
                ans[row][col] = curr->val;
                curr = curr->next;
                col--;
            }
            row--;
            col++;

            while(curr != nullptr and row >=0 and ans[row][col] == -1) {
                ans[row][col] = curr->val;
                curr = curr->next;
                row--;
            }
            row++;
            col++;
            
            m--;
            n++;
        }
        
        return ans;
    }
};