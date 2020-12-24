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
	bool check(TreeNode* root, long long mi, long long mx) {
		if (!root)
			return true;

		if (mi < root->val && root->val < mx)
			return check(root->left, mi, root->val) && check(root->right, root->val, mx);

		return false;
	}

	bool isValidBST(TreeNode* root) {
		return check(root, LONG_MIN, LONG_MAX);
	}
};
