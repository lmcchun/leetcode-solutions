/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int fn(struct TreeNode*);

int rob(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int money1 = 0;
	int money2 = root->val;
	if (root->left != NULL) {
		money1 += rob(root->left);
		money2 += fn(root->left);
	}
	if (root->right != NULL) {
		money1 += rob(root->right);
		money2 += fn(root->right);
	}
	return (money1 > money2) ? money1 : money2;
}

int fn(struct TreeNode* root) {
	int money = 0;
	if (root->left != NULL) {
		money += rob(root->left);
	}
	if (root->right != NULL) {
		money += rob(root->right);
	}
	return money;
}
