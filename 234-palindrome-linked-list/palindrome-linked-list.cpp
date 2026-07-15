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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;
        ListNode* first = head;
        ListNode* second = head;
        while(second && second -> next){
            first = first -> next;
            second = second -> next -> next;
        }

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* after = cur -> next;
        while(cur -> next != first){
            cur -> next = prev;
            prev = cur;
            cur = after;
            after = cur -> next;
        }
        cur -> next = prev;

        if(second == NULL){
            while(first){
                if(first -> val != cur -> val) return false;
                first = first -> next;
                cur = cur -> next;
            }
            return true;
        }
        else{
            first = first -> next;
            while(first){
                if(first -> val != cur -> val) return false;
                first = first -> next;
                cur = cur -> next;
            }
            return true;
        }
        return true;
    }
};