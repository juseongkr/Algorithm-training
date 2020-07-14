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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (!root)
			return ret;

		map<int, int> level;
		queue<pair<TreeNode*, int>> que;
		level[0] = root->val;
		que.push({root, 0});

		while (!que.empty()) {
			auto [cur, dep] = que.front();
			que.pop();

			if (cur->left) {
				level[dep+1] = cur->left->val;
				que.push({cur->left, dep+1});
			}

			if (cur->right) {
				level[dep+1] = cur->right->val;
				que.push({cur->right, dep+1});
			}
		}

		for (const auto l : level)
			ret.push_back(l.second);

		return ret;
	}
};
