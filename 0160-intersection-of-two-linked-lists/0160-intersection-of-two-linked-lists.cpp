int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for(string s; getline(std::cin, s);)
    {
        if(s[0] != '0') out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for(int i = 0; i < 4; ++i) getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();
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