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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow =  head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast && fast->next){
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = head;
        ListNode* nextnode = NULL;
        while(prev){
            nextnode = curr->next;
            curr->next = prev;
            curr = prev;
            prev = nextnode;
        }
    }
};