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
    ListNode* reverse(ListNode *head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* A = reverse(l1);
        ListNode* B = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while(A || B || carry){
            int sum = 0;
            if(A){
                sum += A->val;
                A = A->next;
            }
            if(B) {
                sum += B->val;
                B = B->next;
            }
            sum += carry;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = node;
            carry = sum/10;
        }
        return reverse(dummy->next);
    }
};