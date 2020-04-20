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
	TreeNode* dfs(TreeNode* root, int val) {
		if (!root)
			root = new TreeNode(val);
		else if (root->val < val)
			root->right = dfs(root->right, val);
		else
			root->left = dfs(root->left, val);

		return root;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode *root = nullptr;
		for (const auto node : preorder)
			root = dfs(root, node);

		return root;
	}
};
