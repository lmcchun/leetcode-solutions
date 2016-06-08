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
		vector<vector<int>> levelOrder(TreeNode* root) {
			int level = treeLevel(root);
			vector<vector<int>> result(level, vector<int>());
			dfs(root, result, 0);
			return result;
		}

	private:
		int treeLevel(TreeNode* root) {
			if (root == NULL) {
				return 0;
			}
			return max(treeLevel(root->left), treeLevel(root->right)) + 1;
		}

		void dfs(TreeNode* root, vector<vector<int>>& result, int level) {
			if (root == NULL) {
				return;
			}
			result[level].push_back(root->val);
			dfs(root->left, result, level + 1);
			dfs(root->right, result, level + 1);
		}
};
