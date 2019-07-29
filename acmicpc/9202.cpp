#include <iostream>
#include <set>
using namespace std;

const int dy[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dx[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
const int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
bool visit[4][4];
string board[4];
set<string> st;

class Trie {
public:
	Trie *next[26];
	Trie *fail;
	bool valid;

	Trie() : valid(false), fail(nullptr)
	{
		fill(next, next+26, nullptr);
	}

	~Trie()
	{
		for (int i=0; i<26; ++i)
			if (next[i])
				delete next[i];
	}

	void insert(const char *c)
	{
		if (*c == '\0') {
			valid = true;
		} else {
			int i = *c-'A';
			if (!next[i])
				next[i] = new Trie();
			next[i]->insert(c+1);
		}
	}

	void search(int i, int j, string s)
	{
		if (i < 0 || j < 0 || i >= 4 || j >= 4 || visit[i][j] || s.length() >= 8)
			return;

		visit[i][j] = true;
		if (!next[board[i][j]-'A']) {
			visit[i][j] = false;
			return;
		}

		s = s + board[i][j];
		if (next[board[i][j]-'A']->valid)
			st.insert(s);

		for (int k=0; k<8; ++k)
			next[board[i][j]-'A']->search(i+dy[k], j+dx[k], s);

		visit[i][j] = false;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n;

	cin >> n;
	Trie *root = new Trie();
	for (int i=0; i<n; ++i) {
		cin >> s;
		root->insert(s.c_str());
	}

	cin >> n;
	for (int k=0; k<n; ++k) {
		for (int i=0; i<4; ++i)
			cin >> board[i];

		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				root->search(i, j, "");

		int sum = 0;
		string mx = "";
		for (auto it : st) {
			if (it.length() > mx.length())
				mx = it;
			sum += score[it.length()];
		}
		cout << sum << " " << mx << " " << st.size() << '\n';
		st.clear();
	}

	delete root;
	return 0;
}
