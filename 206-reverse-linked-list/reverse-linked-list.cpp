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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;
        ListNode* first = NULL;
        ListNode* second = head;
        ListNode* third = second -> next;
        while(second -> next){
            second -> next = first;
            first = second;
            second = third;
            third = second -> next;
        }
        second -> next = first;
        return second;
    }
};