/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode* evenList = NULL;
	struct ListNode* p = head;
	struct ListNode** pp = &evenList;
	while (p != NULL) {
		if (p->next != NULL) {
			*pp = p->next;

			p->next = p->next->next;

			(*pp)->next = NULL;
			pp = &((*pp)->next);

			if (p->next == NULL) {
				p->next = evenList;
				break;
			} else {
				p = p->next;
			}
		} else {
			p->next = evenList;
			break;
		}
	}
	return head;
}
