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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        int n = arr.size();
        if(n == 2) return {-1,-1};
        
        int first_pt = INT_MAX,prev,mini = INT_MAX;

        for(int i=1;i<n-1;i++){
            if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1])){ //Local Maxima and Minima condition
                if(first_pt == INT_MAX){
                    first_pt = i;
                    prev = i;
                }
                else{
                    mini = min(mini,i-prev);
                    prev = i;
                }
            }
        }
        if(first_pt == INT_MAX || mini == INT_MAX) return {-1,-1};
        return {mini, prev - first_pt};
    }
};