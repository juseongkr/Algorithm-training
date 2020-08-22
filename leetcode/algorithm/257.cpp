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
	vector<string> vec;
	void dfs(TreeNode* root, string s) {
		if (!root->left && !root->right) {
			vec.push_back(s);
			return;
		}

		if (root->left)
			dfs(root->left, s + "->" + to_string(root->left->val));
		if (root->right)
			dfs(root->right, s + "->" + to_string(root->right->val));
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root)
			return {};
		dfs(root, to_string(root->val));

		return vec;
	}
};
