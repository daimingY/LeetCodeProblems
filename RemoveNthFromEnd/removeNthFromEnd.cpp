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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* toRemove = head;
        for(int i = 0; i < n; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            head = head->next;
            delete toRemove;
            return head;
        }
        temp = temp->next;
        while(temp != NULL){
            temp = temp->next;
            toRemove = toRemove->next;
        }
        temp = toRemove->next;
        toRemove->next = temp->next;
        delete temp;
        return head;
    }
};
