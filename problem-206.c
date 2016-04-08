/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* result = NULL;
	struct ListNode* temp;
	while (head != NULL) {
		temp = head;
		head = temp->next;
		temp->next = result;
		result = temp;
	}
	return result;
}
