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
    ListNode* Merge(ListNode* A,ListNode* B){
        ListNode * dummy = new ListNode(0);
        ListNode * temp = dummy;
        while(A != NULL && B != NULL){
            if(A->val <= B->val){
                temp->next = A;
                A = A->next;
            }
            else{
                temp->next = B;
                B = B->next;
            }
            temp = temp->next;
        }
        if(A != NULL)temp->next = A;
        else temp->next = B;
        return dummy->next;
    }
    ListNode* Middle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = Middle(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return Merge(left,right);
    }
};