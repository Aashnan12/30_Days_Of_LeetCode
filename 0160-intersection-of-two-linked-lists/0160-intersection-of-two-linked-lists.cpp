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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        while(A){
            ListNode* temp = B;
            while(temp){
                if(A==temp) return A;
                temp = temp->next;
            }
            A = A->next;
        }
        return NULL;
    }
};