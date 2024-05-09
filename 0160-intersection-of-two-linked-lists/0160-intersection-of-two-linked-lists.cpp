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
        // while(A){
        //     ListNode* temp = B;
        //     while(temp){
        //         if(A==temp) return A;
        //         temp = temp->next;
        //     }
        //     A = A->next;
        // }
        // return NULL;
        unordered_map<ListNode* , int> mp;
        for(ListNode* p = A; p != NULL; p = p->next){
            mp[p] = p->val;
        }
        for(ListNode* q = B ; q != NULL; q = q->next){
            if(mp.find(q) != mp.end()) return q;
        }
        return NULL;
    }
};