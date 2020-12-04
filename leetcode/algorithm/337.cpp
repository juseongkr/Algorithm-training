/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	unordered_map<TreeNode*, int> dp;

	int rob(TreeNode* root) {
		if (!root)
			return 0;

		if (dp.count(root))
			return dp[root];

		int x = 0;
		if (root->left)
			x += rob(root->left);
		if (root->right)
			x += rob(root->right);

		int y = root->val;
		if (root->left)
			y += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			y += rob(root->right->right) + rob(root->right->left);

		return dp[root] = max(x, y);
	}
};
