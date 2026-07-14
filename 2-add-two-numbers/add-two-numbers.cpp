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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int car = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(t1 != NULL || t2 != NULL){
            int sum = car;
            if(t1){
                sum += t1 -> val;
                t1 = t1 -> next;
            }
            if(t2){
                sum+= t2 -> val;
                t2 = t2 -> next;
            }
            car = sum / 10;
            ListNode* last = new ListNode(sum % 10);
            cur -> next = last;
            cur = cur -> next;
        }
        if(car){
            ListNode* last = new ListNode(car);
            cur -> next = last;
        }
        return dummy -> next;
    }
};