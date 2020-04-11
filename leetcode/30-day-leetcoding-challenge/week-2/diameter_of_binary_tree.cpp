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
	int mx = 0;
	int dfs(TreeNode *root) {
		if (!root)
			return 0;

		int l = dfs(root->left);
		int r = dfs(root->right);

		mx = max(mx, l+r);
		return max(l, r) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
		return mx;
	}
};
