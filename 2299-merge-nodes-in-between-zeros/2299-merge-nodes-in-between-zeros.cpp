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
        ListNode* dummy = new ListNode(111);
        ListNode* curr = dummy;

        head = head->next;
        int sum = 0;

        while(head != NULL){
            
            if(head->val == 0){
                ListNode* newnode = new ListNode(sum);
                curr->next = newnode;
                curr = newnode;
                sum = 0;
            }
            else{
                sum += head->val;
            }
            head = head->next;
        }
        return dummy->next;
    }
};