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
		int minDepth(TreeNode* root) {
			if (root == NULL) {
				return 0;
			}
			if (root->left == NULL) {
				return minDepth(root->right) + 1;
			} else if (root->right == NULL) {
				return minDepth(root->left) + 1;
			} else {
				return min(minDepth(root->left), minDepth(root->right)) + 1;
			}
		}
};

class Solution {
	public:
		int minDepth(TreeNode* root) {
			if (root == NULL) {
				return 0;
			}
			int d = INT_MAX;
			vector<pair<TreeNode*, int>> forest = {make_pair(root, 0)};
			while (!forest.empty()) {
				pair<TreeNode*, int> nodeDepthPair = forest.back();
				TreeNode* node = nodeDepthPair.first;
				int curDepth = nodeDepthPair.second + 1;
				forest.pop_back();

				if (node->left == NULL) {
					if (node->right == NULL) {
						d = min(curDepth, d);
					} else {
						forest.push_back(make_pair(node->right, curDepth));
					}
				} else {
					forest.push_back(make_pair(node->left, curDepth));
					if (node->right != NULL) {
						forest.push_back(make_pair(node->right, curDepth));
					}
				}
			}
			return d;
		}
};
