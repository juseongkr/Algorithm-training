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
class BSTIterator {
public:
	vector<int> nodes;
	int idx = 0;

	BSTIterator(TreeNode* root) {
		inorder(root);
	}

	/** @return the next smallest number */
	int next() {
		return nodes[idx++];
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return idx < nodes.size();
	}

	void inorder(TreeNode* root) {
		if (!root)
			return;

		inorder(root->left);
		nodes.push_back(root->val);
		inorder(root->right);
	}
};
