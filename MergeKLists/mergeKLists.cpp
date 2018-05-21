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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto comp = [](const ListNode* l1, const ListNode* l2) {
			return l1->val > l2->val;
		};
		priority_queue < ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

		for (auto list : lists) {
            if(list)
			    pq.push(list);
		}

		if (pq.empty()) return nullptr;

		ListNode* result = pq.top();
		pq.pop();

		if (result->next)
			pq.push(result->next);
		ListNode* tail = result;

		while (!pq.empty()) {
			tail->next = pq.top();
			pq.pop();
			tail = tail->next;
			if (tail->next) pq.push(tail->next);
		}

		return result;
    }
};
