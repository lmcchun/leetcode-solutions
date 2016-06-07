/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (root == NULL) {
				return true;
			}

			vector<TreeNode*> leftForest = {root->left};
			vector<TreeNode*> rightForest = {root->right};
			while (true) {
				if (leftForest.empty() && rightForest.empty()) {
					return true;
				}
				if (leftForest.empty() || rightForest.empty()) {
					return false;
				}

				TreeNode* leftNode = leftForest.back();
				leftForest.pop_back();

				TreeNode* rightNode = rightForest.back();
				rightForest.pop_back();

				if ((leftNode == NULL) && (rightNode == NULL)) {
					continue;
				}
				if ((leftNode == NULL) || (rightNode == NULL)) {
					return false;
				}
				if (leftNode->val != rightNode->val) {
					return false;
				}

				if (leftNode->right != rightNode->left) {
					if ((leftNode->right == NULL) || (rightNode->left == NULL)) {
						return false;
					}
					leftForest.push_back(leftNode->right);
					rightForest.push_back(rightNode->left);
				}

				if (leftNode->left != rightNode->right) {
					if ((leftNode->left == NULL) || (rightNode->right == NULL)) {
						return false;
					}
					leftForest.push_back(leftNode->left);
					rightForest.push_back(rightNode->right);
				}
			}
			return true;
		}
};

class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (root == NULL) {
				return true;
			} else {
				return isSymmetric(root->left, root->right);
			}
		}

	private:
		bool isSymmetric(TreeNode* left, TreeNode* right) {
			if (left == right) {
				return true;
			}

			if ((left == NULL) || (right == NULL)) {
				return false;
			}

			if (left->val != right->val) {
				return false;
			}

			return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		}
};
