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
	vector<TreeNode*> allPossibleFBT(int N) {
		if (N % 2 == 0)
			return {};

		if (N == 1)
			return {new TreeNode(0)};

		vector<TreeNode*> ret;
		for (int i=1; i<N; i+=2) {
			vector<TreeNode*> left = allPossibleFBT(i);
			vector<TreeNode*> right = allPossibleFBT(N-i-1);

			for (auto l : left) {
				for (auto r : right) {
					TreeNode *node = new TreeNode(0);
					node->left = l;
					node->right = r;
					ret.push_back(node);
				}
			}
		}

		return ret;
	}
};
