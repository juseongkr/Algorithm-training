class Trie {
private:
	class Node {
	public:
		char val;
		bool valid;
		unordered_map<char, Node*> child;
		Node() : val('*'), valid(false) { }
		Node(char c) : val(c), valid(false) { }
	};
	Node *root = nullptr;

public:
	Trie() : root(new Node()) { }

	void insert(string word) {
		Node *cur = root;
		for (const auto c : word) {
			if (!cur->child.count(c))
				cur->child[c] = new Node(c);
			cur = cur->child[c];
		}
		cur->valid = true;
	}

	string search(string num) {
		Node *cur = root;
		string ret;
		for (int i=0; i<num.length(); ++i) {
			int c = (num[i]-'0')^1;
			if (cur->child.count(c+'0')) {
				cur = cur->child[c+'0'];
				ret += "1";
			} else {
				cur = cur->child[(c^1)+'0'];
				ret += "0";
			}
		}
		return ret;
	}
};

class Solution {
public:
	string binary(int num) {
		string ret;
		int cnt = 0;

		while (num) {
			if (num % 2)
				ret += "1";
			else
				ret += "0";
			num /= 2;
			cnt++;
		}
		for (int i=0; i<32-cnt; ++i)
			ret += "0";
		reverse(ret.begin(), ret.end());

		return ret;
	}

	int decimal(string num) {
		int ret = 0;
		long long k = 1;
		for (int i=num.length()-1; i>=0; i--) {
			ret += (num[i]-'0') * k;
			k *= 2;
		}

		return ret;
	}

	int findMaximumXOR(vector<int>& nums) {
		Trie *root = new Trie();
		vector<string> vec;

		for (int i=0; i<nums.size(); ++i) {
			vec.push_back(binary(nums[i]));
			root->insert(vec[i]);
		}

		int ans = 0;
		for (const auto i : vec) {
			string cur = root->search(i);
			ans = max(ans, decimal(cur));
		}
		return ans;
	}
};
