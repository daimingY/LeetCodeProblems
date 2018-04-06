/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // input: two ListNode pointers representing integers in digits
    // output: ListNode pointer to resultant sum in digits
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // initialize variables
        ListNode* retVal = new ListNode(-1);
        ListNode* currListNode = retVal;
        int carryOn = 0;

        // while both have next digit
        while((l1 != nullptr) && (l2 != nullptr)){
            currListNode->next = new ListNode(carryOn);
            currListNode = currListNode->next;
            currListNode->val += l1->val + l2->val;
            carryOn = currListNode->val / 10;
            currListNode->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // only one has next digit
        while(l1 != nullptr){
            currListNode->next = new ListNode(carryOn);
            currListNode = currListNode->next;
            currListNode->val += l1->val;
            carryOn = currListNode->val / 10;
            currListNode->val %= 10;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            currListNode->next = new ListNode(carryOn);
            currListNode = currListNode->next;
            currListNode->val += l2->val;
            carryOn = currListNode->val / 10;
            currListNode->val %= 10;
            l2 = l2->next;
        }

        // deal with final carry on
        if(carryOn == 1){
            currListNode->next = new ListNode(carryOn);
        }
        
        // delete first null ListNode
        currListNode = retVal->next;
        delete retVal;
        retVal = currListNode;
        return retVal;
    }
};