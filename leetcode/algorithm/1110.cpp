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
	unordered_set<int> target;
	vector<TreeNode*> ans;

	void dfs(TreeNode* cur, TreeNode *prev) {
		if (!cur)
			return;

		dfs(cur->left, cur);
		dfs(cur->right, cur);

		if (target.count(cur->val)) {
			if (prev) {
				if (prev->left == cur)
					prev->left = nullptr;
				if (prev->right == cur)
					prev->right = nullptr;
			}
			if (cur->left)
				ans.push_back(cur->left);
			if (cur->right)
				ans.push_back(cur->right);
		} else {
			if (!prev)
				ans.push_back(cur);
		}
	}

	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		for (const auto i : to_delete)
			target.insert(i);

		dfs(root, nullptr);

		return ans;
	}
};
