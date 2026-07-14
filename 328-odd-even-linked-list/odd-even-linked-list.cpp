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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* Ohead = head;
        ListNode* Ehead = head -> next;
        ListNode* temp = Ehead -> next;
        ListNode* temp1 = Ohead;
        ListNode* temp2 = Ehead;
        int cnt = 3;
        while(temp){
            if(cnt % 2){
                //odd
                temp1 -> next = temp;
                temp1 = temp;
            }
            else{
                temp2 -> next = temp;
                temp2 = temp;
            }
            temp = temp -> next;
            cnt++;
        }
        temp1 -> next = Ehead;
        temp2 -> next = NULL;
        return Ohead;
    }
};