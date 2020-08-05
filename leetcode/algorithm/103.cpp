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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (!root)
			return ret;

		vector<int> temp;
		queue<TreeNode*> que;
		que.push(root);
		que.push(nullptr);

		int dir = 0;
		while (!que.empty()) {
			auto cur = que.front();
			que.pop();

			if (cur) {
				temp.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			} else {
				if (dir % 2 == 1)
					reverse(temp.begin(), temp.end());
				ret.push_back(temp);
				temp.clear();
				if (!que.empty())
					que.push(nullptr);
				dir++;
			}
		}

		return ret;
	}
};
