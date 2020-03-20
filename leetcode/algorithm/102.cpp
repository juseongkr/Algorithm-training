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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		queue<TreeNode*> que;

		if (!root)
			return ret;

		que.push(root);
		while (!que.empty()) {
			ret.push_back({});
			int sz = que.size();
			for (int i=0; i<sz; ++i) {
				auto cur = que.front();
				que.pop();
				ret.back().push_back(cur->val);

				if (cur->left)
					que.push(cur->left);

				if (cur->right)
					que.push(cur->right);
			}
		}
		return ret;
	}
};
