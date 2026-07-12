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
    bool hasCycle(ListNode *head) {
        unordered_set <ListNode*> st;
        ListNode* temp = head;
        if(temp == NULL) return false;
        st.insert(temp);
        while (temp -> next){
            temp = temp -> next;
            if(st.find(temp) != st.end()) return true;
            st.insert(temp);
        }
        return false;
    }
};