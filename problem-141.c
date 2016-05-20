/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
	struct ListNode *walker = head;
	struct ListNode *runner = head;
	while ((runner != NULL) && (runner->next != NULL)) {
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner) {
			return true;
		}
	}
	return false;
}
