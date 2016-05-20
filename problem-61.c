/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode* tail = head;
	int length = 1;
	while (tail->next != NULL) {
		tail = tail->next;
		++length;
	}

	k %= length;
	if (k == 0) {
		return head;
	}

	struct ListNode* p = head;
	for (int i = (length - k); i > 1; --i) {
		p = p->next;
	}
	struct ListNode* result = p->next;
	p->next = NULL;

	tail->next = head;

	return result;
}
