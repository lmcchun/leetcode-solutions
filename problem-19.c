/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* 存储从链表尾部算起的 n + 1 个结点 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int m = n + 1;
	struct ListNode** pp = (struct ListNode*) malloc(sizeof(struct ListNode*) * m);
	int length = 0;
	struct ListNode* p = head;
	while (p != NULL) {
		pp[length % m] = p;
		++length;
		p = p->next;
	}

	n %= length;
	if (n == 0) { // 待删除结点是链表第一个结点
		free(head);
		return head->next;
	}

	// 获取所存储的指向待删除结点前一个结点的指针
	int index = length % m;
	free(pp[index]->next);
	pp[index]->next = pp[index]->next->next;

	free(pp);

	return head;
}
