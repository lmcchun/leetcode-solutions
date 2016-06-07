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
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> result;

			vector<TreeNode *> forest;
			if (root != NULL) {
				forest.push_back(root);
			}

			while (!forest.empty()) {
				TreeNode* node = forest.back();
				forest.pop_back();

				result.push_back(node->val);

				if (node->right != NULL) {
					forest.push_back(node->right);
				}
				if (node->left != NULL) {
					forest.push_back(node->left);
				}
			}

			return result;
		}
};
