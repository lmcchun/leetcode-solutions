/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode** pp;
	struct ListNode* temp;
	if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL) {
		return l1;
	} else {
		pp = &l1;
		temp = l2;
		l2 = temp->next;
		temp->next = NULL;
		while (*pp != NULL) {
			if ((*pp)->val > temp->val) {
				temp->next = *pp;
				*pp = temp;
				break;
			} else {
				pp = &((*pp)->next);
			}
		}
		if (*pp == NULL) {
			*pp = temp;
		}
		return mergeTwoLists(l1, l2);
	}
}
