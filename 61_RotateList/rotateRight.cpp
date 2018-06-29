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
    ListNode* rotateRight(ListNode* head, int k) {
        // base case
        if(!head || !k) return head;
        // variables
        ListNode* tail(head), *cur(head), *res;
        // get length
        int len = 1;
        while(tail->next) tail = tail->next, len++;
        // linear traverse
        k = k % len;
        if(!k) return head;
        k = len - k;

        while(--k) cur = cur->next;

        res = cur->next;
        cur->next = NULL;
        tail->next = head;

        return res;
    }
};
