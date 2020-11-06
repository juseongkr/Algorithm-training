/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result;
		queue<TreeNode*> que;
		que.push(root);

		while (!que.empty()) {
			auto cur = que.front();
			que.pop();

			if (cur) {
				que.push(cur->left);
				que.push(cur->right);
			}
			result += cur ? to_string(cur->val) + "," : "null,";
		}

		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.length() == 0)
			return nullptr;

		string s;
		vector<string> vec;
		for (int i=0; i<data.length(); ++i) {
			if (data[i] == ',') {
				vec.push_back(s);
				s = "";
			} else {
				s += data[i];
			}
		}

		if (vec[0] == "null")
			return nullptr;

		TreeNode *root = new TreeNode(stoi(vec[0]));
		queue<TreeNode*> que;
		que.push(root);

		int idx = 1;
		while (!que.empty()) {
			auto cur = que.front();
			que.pop();

			string left = vec[idx++];
			if (left != "null") {
				TreeNode* node = new TreeNode(stoi(left));
				cur->left = node;
				que.push(node);
			}

			string right = vec[idx++];
			if (right != "null") {
				TreeNode* node = new TreeNode(stoi(right));
				cur->right = node;
				que.push(node);   
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
