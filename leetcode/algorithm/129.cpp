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
	int ans = 0;

	void dfs(TreeNode* cur, string s) {
		char p = cur->val + '0';
		if (!cur->left && !cur->right) {
			ans += stoi(s + p);
			return;
		}

		if (cur->left)
			dfs(cur->left, s + p);
		if (cur->right)
			dfs(cur->right, s + p);
	}

	int sumNumbers(TreeNode* root) {
		if (!root)
			return 0;

		dfs(root, "");
		return ans;
	}
};
