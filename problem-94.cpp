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
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;

			vector<TreeNode *> refs;
			vector<TreeNode *> forest;
			if (root != NULL) {
				forest.push_back(root);
			}

			while (!forest.empty()) {
				TreeNode* node = forest.back();
				forest.pop_back();

				if (node->right != NULL) {
					forest.push_back(node->right);
				}

				if (node->left != NULL) {
					TreeNode* newNode = new TreeNode(node->val);
					refs.push_back(newNode);
					forest.push_back(newNode);
					forest.push_back(node->left);
				} else {
					result.push_back(node->val);
				}
			}

			for (TreeNode *node : refs) {
				delete node;
			}

			return result;
		}
};

class Solution {
	public:
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> result;

			vector<TreeNode *> forest;
			if (root != NULL) {
				forest.push_back(root);
			}

			while (!forest.empty()) {
				TreeNode* node = forest.back();
				forest.pop_back();

				if (node->right != NULL) {
					forest.push_back(node->right);
				}

				if (node->left != NULL) {
					forest.push_back(node);
					forest.push_back(node->left);
					node->left = NULL;
					node->right = NULL;
				} else {
					result.push_back(node->val);
				}
			}

			return result;
		}
};
