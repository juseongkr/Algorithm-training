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
	int cur = 0;
	vector<int> vec;
	vector<vector<int>> ans;

	void dfs(TreeNode *root, int sum) {
		if (!root)
			return;

		cur += root->val;
		vec.push_back(root->val);

		if (!root->left && !root->right && cur == sum)
			ans.push_back(vec);

		dfs(root->left, sum);
		dfs(root->right, sum);

		cur -= root->val;
		vec.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		dfs(root, sum);
		return ans;
	}
};
