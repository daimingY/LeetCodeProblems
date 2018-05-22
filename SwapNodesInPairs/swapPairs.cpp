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
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
        /*
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        ListNode* first;
        ListNode* second;
        ListNode* connect;
        first = head;
        if(first->next){
            second = first->next;
        }

        first->next = second->next;
        second->next = first;
        head = second;

        if(first->next!=NULL){
            while(1){
                connect = first;
                second = first->next->next;
                first = first->next;
                if(first==NULL || second == NULL) break;
                first->next = second->next;
                connect->next = second;
                second->next = first;
                if(first->next == NULL){
                    break;
                }
            }
        }
        return head;
        */
    }
};
