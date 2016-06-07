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
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			int level = treeLevel(root);
			vector<vector<int>> result(level, vector<int>());
			dfs(root, result, level - 1);
			return result;
		}

	private:
		int treeLevel(TreeNode* root) {
			if (root == NULL) {
				return 0;
			} else {
				return max(treeLevel(root->left), treeLevel(root->right)) + 1;
			}
		}

		void dfs(TreeNode* root, vector<vector<int>>& result, int index) {
			if (root != NULL) {
				result[index].push_back(root->val);
				dfs(root->left, result, index - 1);
				dfs(root->right, result, index - 1);
			}
		}
};
