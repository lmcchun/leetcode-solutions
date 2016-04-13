/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode** pp;
	struct ListNode* temp;
	if (head == NULL) {
		return head;
	}
	pp = &head;
	while (*pp != NULL) {
		if ((*pp)->next == NULL) {
			break;
		}
		temp = *pp;
		*pp = temp->next;
		temp->next = (*pp)->next;
		(*pp)->next = temp;
		pp = &(temp->next);
	}
	return head;
}
