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
	bool travel(TreeNode *l, TreeNode *r) {
		if (l == NULL && r == NULL)
			return true;

		if (l == NULL || r == NULL)
			return false;

		if (l->val == r->val && travel(l->right, r->left) && travel(l->left, r->right))
			return true;

		return false;
	}

	bool isSymmetric(TreeNode* root) {
		return travel(root, root);
	}
};
