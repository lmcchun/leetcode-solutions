/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
	int leftDepth = 0;
	int rightDepth = 0;
	if (root == NULL) {
		return 0;
	}
	leftDepth = maxDepth(root->left);
	rightDepth = maxDepth(root->right);
	if (leftDepth >= rightDepth) {
		return leftDepth + 1;
	} else {
		return rightDepth + 1;
	}
}
