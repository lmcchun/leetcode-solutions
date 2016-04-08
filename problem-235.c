/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if ((root == NULL) || (p == NULL) || (q == NULL)) {
		return NULL;
	}
	if (p->val < root->val) {
		if (q->val < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		} else {
			return root;
		}
	} else if (p->val > root->val) {
		if (q->val > root->val) {
			return lowestCommonAncestor(root->right, p, q);
		} else {
			return root;
		}
	} else {
		return root;
	}
}
