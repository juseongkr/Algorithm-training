#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
	map<string, Node*> next;
};

Node *root = new Node();
int n, k;

void insert(Node *n, vector<string> &vec, int idx)
{
	if (idx == vec.size())
		return;

	if (!n->next.count(vec[idx]))
		n->next[vec[idx]] = new Node();

	insert(n->next[vec[idx]], vec, idx+1);
}

void dfs(Node *n, int cnt)
{
	for (auto i : n->next) {
		for (int j=0; j<cnt; ++j)
			cout << "--";
		cout << i.first << '\n';
		dfs(i.second, cnt+1);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		string p;
		vector<string> vec;
		for (int j=0; j<k; ++j) {
			cin >> p;
			vec.push_back(p);
		}
		insert(root, vec, 0);
	}
	dfs(root, 0);

	return 0;
}
