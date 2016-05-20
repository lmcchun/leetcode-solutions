/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root) {
	return getTreeDepth(root) != -1;
}

int getTreeDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int leftSubTreeDepth = getTreeDepth(root->left);
	if (leftSubTreeDepth == -1) {
		return -1;
	}

	int rightSubTreeDepth = getTreeDepth(root->right);
	if (rightSubTreeDepth == -1) {
		return -1;
	}

	int diff = leftSubTreeDepth - rightSubTreeDepth;
	if ((diff > 1) || (diff < -1)) {
		return -1;
	}

	return ((diff > 0) ? leftSubTreeDepth : rightSubTreeDepth) + 1;
}
