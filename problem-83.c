/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode* current = head;
	struct ListNode* next;
	while (current != NULL) {
		next = current->next;
		if (next != NULL) {
			if (next->val == current->val) {
				current->next = next->next;
				free(next);
			} else {
				current = next;
			}
		} else {
			break;
		}
	}
	return head;
}
