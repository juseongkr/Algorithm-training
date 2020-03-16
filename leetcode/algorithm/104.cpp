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
	int travel(TreeNode* root, int depth) {
		if (!root)
			return depth;

		return max(travel(root->left, depth+1), travel(root->right, depth+1));
	}

	int maxDepth(TreeNode* root) {
		return travel(root, 0);
	}
};
