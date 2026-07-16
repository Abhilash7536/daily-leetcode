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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int l1 = 0;
        int l2 = 0;
        while(t1 || t2){
            if(t1){
                t1 = t1 -> next;
                l1++;
            }
            if(t2){
                t2 = t2 -> next;
                l2++;
            }
        }
        t1 = headA;
        t2 = headB;
        if(l1 > l2){
            int dif = l1 - l2;
            while(dif--){
                t1 = t1 -> next;
            }
        }
        else if(l2 > l1){
            int dif = l2 - l1;
            while(dif--){
                t2 = t2 -> next;
            } 
        }
        while(t1 && t2){
            if(t1 == t2) return t1;
            else {
                t1 = t1 -> next;
                t2 = t2 -> next;
            }
        }
        return NULL;
    }
};