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
	private:
		int counter;
		int result;
	public:
		int kthSmallest(TreeNode* root, int k) {
			counter = k;
			fn(root);
			return result;
		}

		void fn(TreeNode* root) {
			if (root->left != NULL) {
				fn(root->left);
			}

			--counter;
			if (counter == 0) {
				result = root->val;
				return;
			}

			if (root->right != NULL) {
				fn(root->right);
			}
		}
};

class Solution {
	public:
		int kthSmallest(TreeNode* root, int k) {
			vector<TreeNode*> stack;

			while (root != NULL) {
				stack.push_back(root);
				root = root->left;
			}

			while (k != 0) {
				TreeNode* node = stack.back();
				stack.pop_back();

				--k;

				if (k == 0) {
					return node->val;
				}

				TreeNode* right = node->right;
				while (right != NULL) {
					stack.push_back(right);
					right = right->left;
				}
			}

			return 0; // 根据题目假设, 代码不可能执行到这里
		}
};
