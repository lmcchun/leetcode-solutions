/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL) {
		return head;
	}
	struct ListNode** p = &head;
	int prev = (*p)->val;
	bool needCheckPrev = false;
	while (*p != NULL) {
		if (needCheckPrev && ((*p)->val == prev)) {
			*p = (*p)->next;
		} else if (((*p)->next != NULL) && ((*p)->val == (*p)->next->val)) {
			prev = (*p)->val;
			needCheckPrev = true;
			*p = (*p)->next->next;
		} else {
			needCheckPrev = false;
			p = &((*p)->next);
		}
	}
	return head;
}
