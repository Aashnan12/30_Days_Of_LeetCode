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
    ListNode* addTwoNumbers(ListNode* A, ListNode* B) {

        int carry = 0,sum = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        while(A || B || carry){
            if(A) {
                sum += A->val;
                A = A->next;
            }
            if(B) {
                sum += B->val;
                B = B->next;
            }
            sum += carry;
            head->next = new ListNode(sum % 10);
            head = head->next;
            carry = sum / 10;
            sum = 0;
        }

        return (dummy->next);

    }
};