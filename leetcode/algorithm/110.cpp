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
	bool check;

	int height(TreeNode *root, int depth) {
		if (!root)
			return depth;

		int left = height(root->left, depth+1);
		int right = height(root->right, depth+1);

		if (abs(left-right) >= 2)
			check = false;

		return max(left, right);
	}

	bool isBalanced(TreeNode* root) {
		check = true;
		height(root, 0);
		return check;
	}
};
