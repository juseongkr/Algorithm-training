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
	bool dfs(TreeNode* root, vector<int>& arr, int depth) {
		if (!root)
			return false;

		if (root->val != arr[depth])
			return false;

		if (depth == arr.size()-1)
			return (!root->left && !root->right);

		return dfs(root->left, arr, depth+1) || dfs(root->right, arr, depth+1);
	}

	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		return dfs(root, arr, 0);
	}
};
